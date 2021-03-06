/*
 * SS_sequence.c
 *
 *  Created on: Feb 1, 2020
 *      Author: maciek
 */

#define SS_DEBUG_ENABLED

/* ==================================================================== */
/* ============================= Includes ============================= */
/* ==================================================================== */

#include "SS_sequence.h"

#include "FreeRTOS.h"
#include "SS_com.h"
#include "SS_log.h"
#include "SS_sequence_handlers.h"
#include "semphr.h"
#include "stdbool.h"
#include "string.h"

/* ==================================================================== */
/* ======================== Private datatypes ========================= */
/* ==================================================================== */

typedef struct {
    ComDeviceID device;
    uint8_t id;
    uint8_t operation;
    int16_t value;
    int16_t time;
} SequenceItem;

typedef struct {
    uint8_t size;
    SequenceItem items[MAX_SEQUENCE_ITEMS];
} Sequence;

/* ==================================================================== */
/* =================== Private function prototypes ==================== */
/* ==================================================================== */

static void SS_sequence_start(bool close);
static void SS_sequence_clear(void);
static void SS_sequence_abort(void);
static void SS_sequence_run(void);
static void SS_sequence_ack_item(SequenceItem item);
static void SS_sequence_finish(void);
static SequenceFunction get_sequence_function(ComDeviceID id);
static SequenceFinishFunction get_sequence_abort_function(ComDeviceID id);

/* ==================================================================== */
/* ========================= Global variables ========================= */
/* ==================================================================== */

static Sequence sequence;
static SemaphoreHandle_t sequence_mutex;
static volatile bool abort_sequence;
static volatile bool close_on_finish;

/* ==================================================================== */
/* ========================= Public functions ========================= */
/* ==================================================================== */

void SS_sequence_init(void) {
    sequence_mutex = xSemaphoreCreateBinary();
    assert(sequence_mutex != NULL);
}

int8_t SS_sequence_add(ComDeviceID device, uint8_t id, uint8_t operation, int16_t value, int16_t time) {
    if(sequence.size >= MAX_SEQUENCE_ITEMS) {
        SS_error("Sequence is full, dropping");
        return -1;
    }
    SequenceItem new_item = {
        .device = device,
        .id = id,
        .operation = operation,
        .value = value,
        .time = time};
    uint8_t i;
    for(i = 0; i < sequence.size; i++) {
        if(time < sequence.items[i].time) {
            memmove(&sequence.items[i + 1], &sequence.items[i], (sequence.size - i) * sizeof(SequenceItem));
            break;
        }
    }
    sequence.items[i] = new_item;
    sequence.size++;
    return 0;
}

ComStatus SS_sequence_com_service(ComFrame *frame) {
    ComSequenceID msgID = frame->operation;
    switch(msgID) {
        case COM_SEQUENCE_CLEAR:
            SS_sequence_clear();
            break;
        case COM_SEQUENCE_START:
            SS_sequence_start(frame->payload);
            break;
        case COM_SEQUENCE_ABORT:
            SS_sequence_abort();
            break;
        default:
            SS_error("Unhandled Com sequence service: %d\r\n", msgID);
            return COM_ERROR;
    }
    return COM_OK;
}

void SS_sequence_task(void *pvParameters) {
    while(true) {
        if(xSemaphoreTake(sequence_mutex, portMAX_DELAY) == pdTRUE) {
            SS_sequence_run();
        }
    }
}

/* ==================================================================== */
/* ======================== Private functions ========================= */
/* ==================================================================== */

static SequenceFunction get_sequence_function(ComDeviceID id) {
    for(uint8_t i = 0; i < sizeof(sequence_handlers) / sizeof(sequence_handlers[0]); i++) {
        if(sequence_handlers[i].device == id) {
            return sequence_handlers[i].run;
        }
    }
    return NULL;
}

static SequenceFinishFunction get_sequence_abort_function(ComDeviceID id) {
    for(uint8_t i = 0; i < sizeof(sequence_handlers) / sizeof(sequence_handlers[0]); i++) {
        if(sequence_handlers[i].device == id) {
            return sequence_handlers[i].finish;
        }
    }
    return NULL;
}

static void SS_sequence_run(void) {
    if(sequence.size == 0) {
        SS_error("Trying to run an empty sequence");
        return;
    }
    SS_debugln("Sequence started");
    for(uint8_t i = 0; i < sequence.size; i++) {
        SequenceItem item = sequence.items[i];
        int16_t delay = i == 0 ? item.time : item.time - sequence.items[i - 1].time;
        if(abort_sequence) {
            abort_sequence = false;
            return;
        }
        vTaskDelay(pdMS_TO_TICKS(delay));
        if(abort_sequence) {
            abort_sequence = false;
            return;
        }
        SequenceFunction function = get_sequence_function(item.device);
        if(function && function(item.id, item.operation, item.value) == COM_OK) {
            SS_sequence_ack_item(item);
        } else {
            /* TODO nack item */
        }
    }
    if(close_on_finish) {
        SS_sequence_finish();
    }
    SS_debugln("Sequence finished");
}

static void SS_sequence_ack_item(SequenceItem item) {
    Com2xInt16 val = {
        .val = item.value,
        .time = item.time};
    uint32_t payload;
    memcpy(&payload, &val, sizeof(uint32_t));
    ComFrame sequence_frame = {
        .priority = COM_LOW_PRIORITY,
        .action = COM_SEQUENCE,
        .source = SS_com_get_board_id(),
        .destination = COM_GRAZYNA_ID,
        .data_type = INT16x2,
        .id = item.id,
        .device = item.device,
        .operation = item.operation,
        .payload = payload,
    };
    SS_com_transmit(&sequence_frame);
}

static void SS_sequence_finish(void) {
    for(uint8_t i = 0; i < sequence.size; i++) {
        SequenceItem item = sequence.items[i];
        SequenceFinishFunction function = get_sequence_abort_function(item.device);
        if(function != NULL) {
            function(item.id);
        }
    }
}

static void SS_sequence_start(bool close) {
    close_on_finish = close;
    xSemaphoreGive(sequence_mutex);
}

static void SS_sequence_clear(void) {
    memset(&sequence, 0, sizeof(sequence));
    SS_debugln("Sequence cleared");
}

static void SS_sequence_abort(void) {
    SS_debugln("Sequence aborted");
    abort_sequence = true;
    SS_sequence_finish();
}

