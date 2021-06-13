/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern uint8_t txbuff;
extern uint8_t rxbuff;
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define T_LOOP_LED_Pin GPIO_PIN_0
#define T_LOOP_LED_GPIO_Port GPIOC
#define T_IND_LED_Pin GPIO_PIN_1
#define T_IND_LED_GPIO_Port GPIOC
#define T_MODE_Pin GPIO_PIN_15
#define T_MODE_GPIO_Port GPIOA
#define T_MODE_EXTI_IRQn EXTI15_10_IRQn
#define BARO_SCLK_Pin GPIO_PIN_3
#define BARO_SCLK_GPIO_Port GPIOB
#define BARO_MISO_Pin GPIO_PIN_4
#define BARO_MISO_GPIO_Port GPIOB
#define BARO_MOSI_Pin GPIO_PIN_5
#define BARO_MOSI_GPIO_Port GPIOB
#define MS56_CS_Pin GPIO_PIN_8
#define MS56_CS_GPIO_Port GPIOB
#define MS58_CS_Pin GPIO_PIN_9
#define MS58_CS_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define RADEKS_TESTER
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
