/**
  * SS_log.h
  *
  *  Created on: May 2, 2020
  *      Author: Maciek
 **/

#ifndef SS_LOG_H
#define SS_LOG_H

/* ==================================================================== */
/* ============================= Includes ============================= */
/* ==================================================================== */

#include "printf.h"
#include "assert.h"
#include "stdbool.h"
#include "stm32f4xx_hal.h"

/* ==================================================================== */
/* ========================= Public functions ========================= */
/* ==================================================================== */

void SS_log_init(UART_HandleTypeDef *huart);
void SS_log_buf_put(char data);
void SS_log_buf_flush(void);
void SS_log_tx_isr(UART_HandleTypeDef *huart);

void SS_print(const char *format, ...);
#define SS_println(format, ...) SS_print(format "\r\n", ##__VA_ARGS__)
#define SS_error(format, ...) SS_print("\x01b[41mERROR\x01b[0m@ " format "\r\n", ##__VA_ARGS__)

bool SS_print_no_flush_start();
void SS_print_no_flush_end();
void SS_print_no_flush(const char *format, ...);

#endif //SS_LOG_H
