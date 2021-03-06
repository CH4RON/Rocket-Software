/*
 * SS_dynamixel_com.h
 *
 *  Created on: 01.05.2020
 *      Author: Maciek
 */

#ifndef SS_DYNAMIXEL_COM_H_
#define SS_DYNAMIXEL_COM_H_

#include "SS_com.h"

/* ==================================================================== */
/* ============================ Datatypes ============================= */
/* ==================================================================== */

typedef enum {
    COM_DYNAMIXEL_OPEN = 0x01,
    COM_DYNAMIXEL_CLOSE,
    COM_DYNAMIXEL_OPENED_POSITION,
    COM_DYNAMIXEL_CLOSED_POSITION,
    COM_DYNAMIXEL_POSITION,
    /* COM_DYNAMIXEL_DISABLE, */
} ComDynamixelID;

/* ==================================================================== */
/* ==================== Public function prototypes ==================== */
/* ==================================================================== */

ComStatus SS_dynamixel_com_service(ComFrame *frame);
ComStatus SS_dynamixel_com_request(ComFrame *frame);
ComStatus SS_dynamixel_com_sequence_validate(ComFrame *frame);
ComStatus SS_dynamixel_sequence(uint8_t id, uint8_t operation, int16_t value);
void SS_dynamixel_sequence_finish(uint8_t id);

#endif
