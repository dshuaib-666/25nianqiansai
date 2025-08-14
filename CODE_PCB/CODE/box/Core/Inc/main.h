/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define motor_en_Pin GPIO_PIN_15
#define motor_en_GPIO_Port GPIOE
#define IRQ_24L01_Pin GPIO_PIN_12
#define IRQ_24L01_GPIO_Port GPIOB
#define CE_24L01_Pin GPIO_PIN_8
#define CE_24L01_GPIO_Port GPIOD
#define CSN_24L01_Pin GPIO_PIN_9
#define CSN_24L01_GPIO_Port GPIOD
#define FOURG_Pin GPIO_PIN_6
#define FOURG_GPIO_Port GPIOC
#define ziwaia_Pin GPIO_PIN_11
#define ziwaia_GPIO_Port GPIOA
#define ziwaixian2_Pin GPIO_PIN_12
#define ziwaixian2_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
#define CS_24L01_Pin       	CSN_24L01_Pin
#define NRF_CS_GPIO_Port 	CSN_24L01_GPIO_Port
#define NRF_CS_Pin 			CSN_24L01_Pin

#define NRF_IRQ_Pin 		    IRQ_24L01_Pin
#define NRF_IRQ_GPIO_Port 	IRQ_24L01_GPIO_Port
#define NRF_CE_Pin     		CE_24L01_Pin
#define NRF_CE_GPIO_Port 	CE_24L01_GPIO_Port
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
