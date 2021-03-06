/*
 * SS_dynamixel.h
 *
 *  Created on: Dec 29, 2019
 *      Author: maciek
 *
 *  Supports Dynamixel Protocol 2.0
 */

#ifndef SS_DYNAMIXEL_H_
#define SS_DYNAMIXEL_H_

/* ==================================================================== */
/* ============================= Includes ============================= */
/* ==================================================================== */

#include "FreeRTOS.h"
#ifdef SS_USE_SUPPLY
#include "SS_supply.h"
#endif
#include "semphr.h"
#include "stdbool.h"
#include "stm32f4xx_hal.h"

/* ==================================================================== */
/* ============================= Macros =============================== */
/* ==================================================================== */

#define MAX_PACKET_LENGTH 20
#define UART_TIMEOUT 20

/* ==================================================================== */
/* ============================ Datatypes ============================= */
/* ==================================================================== */

typedef enum {
    /* Instruction that checks whether the Packet has arrived to a device with the same ID as Packet ID */
    DYNAMIXEL_PING = 0x01,
    /* Instruction to read data from the Device */
    DYNAMIXEL_READ = 0x02,
    /* Instruction to write data on the Device */
    DYNAMIXEL_WRITE = 0x03,
    /* Instruction that registers the Instruction Packet to a standby status; Packet is later executed through the Action command */
    DYNAMIXEL_REG_WRITE = 0x04,
    /* Instruction that executes the Packet that was registered beforehand using Reg Write */
    DYNAMIXEL_ACTION = 0x05,
    /* Instruction that resets the Control Table to its initial factory default settings */
    DYNAMIXEL_FACTORY_RESET = 0x06,
    /* Instruction to reboot the Device */
    DYNAMIXEL_REBOOT = 0x08,
    /* Instruction to reset certain information */
    DYNAMIXEL_CLEAR = 0x10,
    /* Return Instruction for the Instruction Packet */
    DYNAMIXEL_STATUS = 0x55,
    /* For multiple devices, Instruction to read data from the same Address with the same length at once */
    DYNAMIXEL_SYNC_READ = 0x82,
    /* For multiple devices, Instruction to write data on the same Address with the same length at once */
    DYNAMIXEL_SYNC_WRITE = 0x83,
    /* For multiple devices, Instruction to read data from different Addresses with different lengths at once */
    DYNAMIXEL_BULK_READ = 0x92,
    /* For multiple devices, Instruction to write data on different Addresses with different lengths at once */
    DYNAMIXEL_BULK_WRITE = 0x93,
} DynamixelInstruction;

typedef enum {
    /* Success */
    DYNAMIXEL_RESULT_OK = 0x00,
    /* Failed to process the sent Instruction Packet */
    DYNAMIXEL_RESULT_FAIL = 0x01,
    /* Undefined Instruction has been used
     * Action has been used without Reg Write */
    DYNAMIXEL_INSTRUCTION_ERROR = 0x02,
    /* CRC of the sent Packet does not match */
    DYNAMIXEL_SENT_CRC_ERROR = 0x03,
    /* Data to be written in the corresponding Address is outside the range of the minimum/maximum value */
    DYNAMIXEL_DATA_RANGE_ERROR = 0x04,
    /* Attempt to write Data that is shorter than the data length of the corresponding Address
     * (ex: when you attempt to only use 2 bytes of a item that has been defined as 4 bytes) */
    DYNAMIXEL_DATA_LENGTH_ERROR = 0x05,
    /* Data to be written in the corresponding Address is outside of the Limit value */
    DYNAMIXEL_DATA_LIMIT_ERROR = 0x06,
    /* Attempt to write a value in an Address that is Read Only or has not been defined
     * Attempt to read a value in an Address that is Write Only or has not been defined
     * Attempt to write a value in the ROM domain while in a state of Torque Enable(ROM Lock) */
    DYNAMIXEL_ACCESS_ERROR = 0x07,
    /* CRC of the received Packet does not match */
    DYNAMIXEL_REC_CRC_ERROR = 0x08,
    /* Another transmission in progress, action added to queue */
    DYNAMIXEL_BUSY = 0x09
} DynamixelStatus;

typedef enum {
    /* EEPROM */
    DYNAMIXEL_MODEL_NUMBER              = 0,
    DYNAMIXEL_MODEL_INFORMATION         = 2,
    DYNAMIXEL_FIRMWARE_VERSION          = 6,
    DYNAMIXEL_ID                        = 7,
    DYNAMIXEL_BAUD_RATE                 = 8,
    DYNAMIXEL_RETURN_DELAY_TIME         = 9,
    DYNAMIXEL_DRIVE_MODE                = 10,
    DYNAMIXEL_OPERATING_MODE            = 11,
    DYNAMIXEL_SECONDARY_ID              = 12,
    DYNAMIXEL_PROTOCOL_TYPE             = 13,
    DYNAMIXEL_HOMING_OFFSET             = 20,
    DYNAMIXEL_MOVING_THRESHOLD          = 24,
    DYNAMIXEL_TEMPERATURE_LIMIT         = 31,
    DYNAMIXEL_MAX_VOLTAGE_LIMIT         = 32,
    DYNAMIXEL_MIN_VOLTAGE_LIMIT         = 34,
    DYNAMIXEL_PWM_LIMIT                 = 36,
    DYNAMIXEL_CURRENT_LIMIT             = 38,
    DYNAMIXEL_VELOCITY_LIMIT            = 44,
    DYNAMIXEL_MAX_POSITION_LIMIT        = 48,
    DYNAMIXEL_MIN_POSITION_LIMIT        = 52,
    DYNAMIXEL_EXTERNAL_PORT_MODE_1      = 56,
    DYNAMIXEL_EXTERNAL_PORT_MODE_2      = 57,
    DYNAMIXEL_EXTERNAL_PORT_MODE_3      = 58,
    DYNAMIXEL_SHUTDOWN                  = 63,
    /* RAM */
    DYNAMIXEL_TORQUE_ENABLE             = 64,
    DYNAMIXEL_LED                       = 65,
    DYNAMIXEL_STATUS_RETURN_LEVEL       = 68,
    DYNAMIXEL_REGISTERED_INSTRUCTION    = 69,
    DYNAMIXEL_HARDWARE_ERROR_STATUS     = 70,
    DYNAMIXEL_VELOCITY_I_GAIN           = 76,
    DYNAMIXEL_VELOCITY_P_GAIN           = 78,
    DYNAMIXEL_POSITION_D_GAIN           = 80,
    DYNAMIXEL_POSITION_I_GAIN           = 82,
    DYNAMIXEL_POSITION_P_GAIN           = 84,
    DYNAMIXEL_FEEDFORWARD_2ND_GAIN      = 88,
    DYNAMIXEL_FEEDFORWARD_1ST_GAIN      = 90,
    DYNAMIXEL_BUS_WATCHDOG              = 98,
    DYNAMIXEL_GOAL_PWM                  = 100,
    DYNAMIXEL_GOAL_CURRENT              = 102,
    DYNAMIXEL_GOAL_VELOCITY             = 104,
    DYNAMIXEL_PROFILE_ACCELERATION      = 108,
    DYNAMIXEL_PROFILE_VELOCITY          = 112,
    DYNAMIXEL_GOAL_POSITION             = 116,
    DYNAMIXEL_REALTIME_TICK             = 120,
    DYNAMIXEL_MOVING                    = 122,
    DYNAMIXEL_MOVING_STATUS             = 123,
    DYNAMIXEL_PRESENT_PWM               = 124,
    DYNAMIXEL_PRESENT_CURRENT           = 126,
    DYNAMIXEL_PRESENT_VELOCITY          = 128,
    DYNAMIXEL_PRESENT_POSITION          = 132,
    DYNAMIXEL_VELOCITY_TRAJECTORY       = 136,
    DYNAMIXEL_POSITION_TRAJECTORY       = 140,
    DYNAMIXEL_PRESENT_INPUT             = 144,
    DYNAMIXEL_PRESENT_TEMPERATURE       = 146,
    DYNAMIXEL_EXTERNAL_PORT_DATA_1      = 152,
    DYNAMIXEL_EXTERNAL_PORT_DATA_2      = 154,
    DYNAMIXEL_EXTERNAL_PORT_DATA_3      = 156,
    DYNAMIXEL_INDIRECT_ADDRESS_1        = 168,
    DYNAMIXEL_INDIRECT_ADDRESS_2        = 170,
    DYNAMIXEL_INDIRECT_ADDRESS_3        = 172,
    DYNAMIXEL_INDIRECT_ADDRESS_26       = 218,
    DYNAMIXEL_INDIRECT_ADDRESS_27       = 220,
    DYNAMIXEL_INDIRECT_ADDRESS_28       = 222,
    DYNAMIXEL_INDIRECT_DATA_1           = 224,
    DYNAMIXEL_INDIRECT_DATA_2           = 225,
    DYNAMIXEL_INDIRECT_DATA_3           = 226,
    DYNAMIXEL_INDIRECT_DATA_26          = 249,
    DYNAMIXEL_INDIRECT_DATA_27          = 250,
    DYNAMIXEL_INDIRECT_DATA_28          = 251,
    DYNAMIXEL_INDIRECT_ADDRESS_29       = 578,
    DYNAMIXEL_INDIRECT_ADDRESS_30       = 580,
    DYNAMIXEL_INDIRECT_ADDRESS_31       = 582,
    DYNAMIXEL_INDIRECT_ADDRESS_54       = 628,
    DYNAMIXEL_INDIRECT_ADDRESS_55       = 630,
    DYNAMIXEL_INDIRECT_ADDRESS_56       = 632,
    DYNAMIXEL_INDIRECT_DATA_29          = 634,
    DYNAMIXEL_INDIRECT_DATA_30          = 635,
    DYNAMIXEL_INDIRECT_DATA_31          = 636,
    DYNAMIXEL_INDIRECT_DATA_54          = 659,
    DYNAMIXEL_INDIRECT_DATA_55          = 660,
    DYNAMIXEL_INDIRECT_DATA_56          = 661,
} Dynamixel_ID;

typedef struct {
    uint8_t id;
    int32_t goal_position;
    int32_t present_position;
    int32_t closed_position;
    int32_t opened_position;
    uint16_t present_current;
    float supply_current;
    uint8_t temperature;
    bool moving;
    bool torque_enabled;
    uint8_t tx_packet_buff[MAX_PACKET_LENGTH];
    uint8_t rx_packet_buff[MAX_PACKET_LENGTH];
    uint16_t rec_size;
    SemaphoreHandle_t mutex;
    SemaphoreHandle_t transmission_semaphore;
    QueueHandle_t tx_queue;
    DynamixelStatus last_status;
    bool systick_enabled;
    bool connected;
    uint16_t connection_timeout;
    UART_HandleTypeDef *huart;
    GPIO_TypeDef *DE_Port;
    uint16_t DE_Pin;
#ifdef SS_USE_SUPPLY
    Supply *supply;
#endif
} Dynamixel;

typedef struct __attribute__((packed)) {
    uint32_t header : 24;
    uint8_t reserved;
    uint8_t packetID;
    uint16_t length;
    uint8_t instruction;
} InstructionPacket;

typedef struct __attribute__((packed)) {
    uint32_t header : 24;
    uint8_t reserved;
    uint8_t packetID;
    uint16_t length;
    uint8_t instruction;
    uint8_t error;
} Status_packet;

typedef struct {
    uint8_t packet[MAX_PACKET_LENGTH];
    uint16_t packet_size;
    uint16_t rec_size;
    void *data;
    bool torque_status;
} DynamixelMessage;

/* ==================================================================== */
/* ========================= Extern variables ========================= */
/* ==================================================================== */

extern Dynamixel dynamixel;

/* ==================================================================== */
/* ==================== Public function prototypes ==================== */
/* ==================================================================== */

/***************** API *****************/

DynamixelStatus SS_dynamixel_init(Dynamixel *servo);
DynamixelStatus SS_dynamixel_open(Dynamixel *servo);
DynamixelStatus SS_dynamixel_close(Dynamixel *servo);
DynamixelStatus SS_dynamixel_enable_torque(Dynamixel *servo);
DynamixelStatus SS_dynamixel_disable_torque(Dynamixel *servo);
DynamixelStatus SS_dynamixel_enable_led(Dynamixel *servo);
DynamixelStatus SS_dynamixel_disable_led(Dynamixel *servo);
DynamixelStatus SS_dynamixel_check_position(Dynamixel *servo, int32_t position);
DynamixelStatus SS_dynamixel_set_goal_position(Dynamixel *servo, int32_t position);
DynamixelStatus SS_dynamixel_set_velocity(Dynamixel *servo, uint32_t velocity);
DynamixelStatus SS_dynamixel_set_velocity_limit(Dynamixel *servo, uint32_t limit);
DynamixelStatus SS_dynamixel_set_opened_position(Dynamixel *servo, int32_t position);
DynamixelStatus SS_dynamixel_set_closed_position(Dynamixel *servo, int32_t position);
DynamixelStatus SS_dynamixel_get_position(Dynamixel *servo);
DynamixelStatus SS_dynamixel_get_moving(Dynamixel *servo);
DynamixelStatus SS_dynamixel_get_current(Dynamixel *servo);
DynamixelStatus SS_dynamixel_get_temperature(Dynamixel *servo);

/******** Polling instructions *********/

DynamixelStatus SS_dynamixel_write(Dynamixel *servo, uint16_t reg, void *data, uint16_t size);
DynamixelStatus SS_dynamixel_read(Dynamixel *servo, uint16_t reg, void *data, uint16_t size);
DynamixelStatus SS_dynamixel_factory_reset(Dynamixel *servo);
DynamixelStatus SS_dynamixel_ping(Dynamixel *servo);

/************** Callabcks ***************/

void SS_dynamixel_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void SS_dynamixel_UART_TxCpltCallback(UART_HandleTypeDef *huart);

#endif /* SS_DYNAMIXEL_H_ */
