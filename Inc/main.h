/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
uint8_t search_sensors(void);

/* USER CODE BEGIN EFP */
void ShowLcdMain(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOA
#define KEY_UP_Pin GPIO_PIN_2
#define KEY_UP_GPIO_Port GPIOA
#define KEY_DOWN_Pin GPIO_PIN_3
#define KEY_DOWN_GPIO_Port GPIOA
#define KEY_LEFT_Pin GPIO_PIN_4
#define KEY_LEFT_GPIO_Port GPIOA
#define KEY_RIGHT_Pin GPIO_PIN_5
#define KEY_RIGHT_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_6
#define LED3_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_10
#define LCD_RST_GPIO_Port GPIOB
#define LCD_DI_Pin GPIO_PIN_11
#define LCD_DI_GPIO_Port GPIOB
#define LCD_CLK_Pin GPIO_PIN_12
#define LCD_CLK_GPIO_Port GPIOB
#define LCD_SHIFT_Pin GPIO_PIN_13
#define LCD_SHIFT_GPIO_Port GPIOB
#define LCD_E_Pin GPIO_PIN_14
#define LCD_E_GPIO_Port GPIOB
#define LCD_DATA_Pin GPIO_PIN_15
#define LCD_DATA_GPIO_Port GPIOB
#define LCD_CS1_Pin GPIO_PIN_8
#define LCD_CS1_GPIO_Port GPIOB
#define LCD_CS2_Pin GPIO_PIN_9
#define LCD_CS2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
