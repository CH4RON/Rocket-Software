/*
 * SS_com_protocol.h
 *
 *  Created on: Jan 16, 2020
 *      Author: maciek
 */

#ifndef SS_COM_H
#define SS_COM_H

/* ==================================================================== */
/* ============================= Includes ============================= */
/* ==================================================================== */

#include "FreeRTOS.h"
#include "SS_com_ids.h"
#include "queue.h"
#include "stdint.h"

/* ==================================================================== */
/* ============================= Macros =============================== */
/* ==================================================================== */
#define SS_COM_TX_QUEUE_SIZE 8

/* ==================================================================== */
/* ============================ Datatypes ============================= */
/* ==================================================================== */

typedef struct __attribute__((packed)) {
    ComBoardID destination : 5;
    ComPriority priority : 3;
    ComActionID action : 3;
    ComBoardID source : 5;
    ComDeviceID device : 6;
    uint32_t id : 6;
    ComDataType data_type : 4;
    uint8_t operation;
    uint32_t payload;
} ComFrame;

typedef struct {
    void (*fun)(ComFrame *);
    uint8_t group_id;
    ComPriority priority;
} ComFifoManager;

typedef enum {
    COM_OK,
    COM_ERROR
} ComStatus;

typedef struct {
    int16_t time;
    int16_t val;
} Com2xInt16;

/* ==================================================================== */
/* ==================== Public function prototypes ==================== */
/* ==================================================================== */

void SS_com_message_received(ComFrame *frame);
void SS_com_init(ComBoardID board);
void SS_com_add_to_tx_queue(ComFrame *frame, void (*sender_fun)(ComFrame *), QueueHandle_t queue);
void SS_com_transmit(ComFrame *frame);
void SS_com_add_payload_to_frame(ComFrame *frame, ComDataType type, void *payload);
void SS_com_rx_handler_task(void *pvParameters);
ComBoardID SS_com_get_board_id(void);

#endif /* SS_COM_H */
