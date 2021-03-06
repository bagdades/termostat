/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "rtc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "scheduler.h"
#include "lcdwg.h"
#include "printf-stdarg.h"
#include "ds18b20.h"
#include "onewire.h"
#include "m_rtc_2001.h"
#include "key.h"
#include "menu.h"
#include "init.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t aShowTime[TIME_BUFFER_LENGTH] = {0};
uint8_t aShowDate[DATE_BUFFER_LENGTH] = {0};
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
uint8_t gSensorIDs[MAXSENSORS][OW_ROMCODE_SIZE];
char owIDString[MAXSENSORS][17];
uint8_t nSensors;
uint8_t ticksBlink = 0;
sensorData_t sensorInside;
sensorData_t sensorOutside;
sensorData_t sensorCooland;
/* uint8_t keyPressed; */
uint8_t resultMeasureOutside[3];
uint8_t resultMeasureInside[3];
uint8_t resultMeasureCoolant[3];
extern uint8_t tempLcd[];
extern stateElement startState;
extern stateElement settingState;
extern int16_t settedComfortTemp;
extern int16_t settedWorkTimeTemp;
extern int16_t settedSleepTimeTemp;
extern char variableChar[VARIABLE_CHAR_DATA_LENGTH];
extern const char *dayOfWeek[7];
const char *modeWorkText[3] = {
	"Auto",
	"Manual",
	"OFF"
};
const char noSensor[] = "---";
uint8_t modeWorkVar = AUTO_MODE_WORK;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Show_RTC_Calendar(void);
void setDataTime(void);
uint8_t DS18X20_search_sensors(uint8_t sensorID[][OW_ROMCODE_SIZE]);
void LedBlink1(void);
void LedBlink2(void);
void StartMeasure(void);
void ReadMeasure(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
	HAL_RTCEx_SetSecond_IT(&hrtc);
	/* setDataTime(); */
	mRTC_Begin(&hrtc);
	Show_RTC_Calendar();
	OW_Init();
	nSensors = DS18X20_search_sensors(gSensorIDs);
	InitMain();
	/* sensorInside.present = 1; */
	OS_AddTask(LedBlink1, 0, 200);
	OS_AddTask(LedBlink2, 100, 500);
	OS_AddTask(StartMeasure, 0, 0);
	OS_AddTask(KeyHand, 0, 32);
	LcdInit();
	LcdShow();
  /* USER CODE END 2 */
 
 

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
		OS_Dispatch();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void ShowLcdMain(void)
{
	LcdClear();
	rect_t rec;
	/* Show temperature inside */
	RECT_SET(rec, 0, 11, 71, 35);
	if (sensorInside.present) 
	{
		TempOut(resultMeasureInside);
		LcdDrawText(rec, DT_LEFT | DT_VCENTER, Font, LCD_MODE_NORM, (const char*)tempLcd);
	}
	else LcdDrawText(rec, DT_LEFT | DT_VCENTER, Font, LCD_MODE_NORM, noSensor);
	/* Show temperature outside */
	RECT_SET(rec, 84, 19, LCD_X_RES - 86, 11);
	if (sensorOutside.present) 
	{
		TempOut(resultMeasureOutside);
		LcdDrawText(rec, DT_CENTER | DT_VCENTER, Arial9_b, LCD_MODE_NORM, (const char*)tempLcd);
	}
	else LcdDrawText(rec, DT_CENTER | DT_VCENTER, Arial9_b, LCD_MODE_NORM, noSensor);
	/* Show temperature water */
	RECT_SET(rec, 84, LCD_Y_RES - 25, LCD_X_RES - 86, 11);
	if (sensorCooland.present) 
	{
		TempOut(resultMeasureCoolant);
		LcdDrawText(rec, DT_CENTER | DT_VCENTER, Arial9_b, LCD_MODE_NORM, (const char*)tempLcd);
	}
	else LcdDrawText(rec, DT_CENTER | DT_VCENTER, Arial9_b, LCD_MODE_NORM, noSensor);
	/* Show frame */
	LcdDrawFrame(84, LCD_X_RES - 1, 10, LCD_Y_RES - 14, LCD_MODE_NORM);
	RECT_SET(rec, 84, 10, LCD_X_RES - 85, 9);
	LcdDrawText(rec, DT_CENTER | DT_VCENTER, Arial7, LCD_MODE_INVERSE, "Outside");
	RECT_SET(rec, 84, 30, LCD_X_RES - 85, 9);
	LcdDrawText(rec, DT_CENTER | DT_VCENTER, Arial7, LCD_MODE_INVERSE, "Coolant");
	/* Show date */
	RECT_SET(rec, 64, 0, 63, 10);
	LcdDrawText(rec, DT_RIGHT, Arial9_b, LCD_MODE_NORM, (const char*)aShowDate);
	/* Show time */
	/* RECT_SET(rec, 0, 53, 63, 10); */
	RECT_SET(rec, 0, 0, 50, 10);
	LcdDrawText(rec, DT_LEFT, Arial9_b, LCD_MODE_NORM, (const char*)aShowTime);
	/* Show day of week */
	RECT_SET(rec, 55, 0, 20, 10);
	uint8_t dayWeek = mRTC_GetWeekDay(&hrtc);
	LcdDrawText(rec, DT_CENTER, Arial9_b, LCD_MODE_NORM, dayOfWeek[dayWeek]);
	/* Show setted temperature */
	RECT_SET(rec, 0, 53, 21, 10);
	LcdDrawText(rec, DT_LEFT, Arial9_b, LCD_MODE_NORM, "Set:");
	RECT_SET(rec, 22, 53, 24, 10);
	int16_t tempTemp = TermGetWorkTemp();
	if (tempTemp) 
	{
		VariableToLcd(&tempTemp, variableChar,  COMMA);
		LcdDrawText(rec, DT_LEFT, Arial9_b, LCD_MODE_NORM, variableChar);
	}
	else LcdDrawText(rec, DT_LEFT, Arial9_b, LCD_MODE_NORM, " ---");
	/* Show mode work */
	RECT_SET(rec, 84, 52, LCD_X_RES - 84 - 1, 11);
	LcdDrawText(rec, DT_CENTER | DT_VCENTER, Arial9_b, LCD_MODE_INVERSE, modeWorkText[modeWorkVar]);
}
void HAL_RTCEx_RTCEventCallback(RTC_HandleTypeDef* hrtc)
{
	Show_RTC_Calendar();
}

void Show_RTC_Calendar(void)
{
	mRTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	sprintf((char*)aShowTime, "%.2d:%.2d:%.2d", sTime.Hours, sTime.Minutes, sTime.Seconds);
	mRTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	sprintf((char*)aShowDate, "%.2d/%.2d/%.2d", sDate.Date, sDate.Month, sDate.Year);
}

void setDataTime(void)
{
	sTime.Hours = 21;
	sTime.Minutes = 20;
	sTime.Seconds = 0;
	if (mRTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK) 
	{
		Error_Handler();
	}
	sDate.Date = 7;
	sDate.Month = 11;
	sDate.Year = 19;
	if (mRTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK) 
	{
		Error_Handler();
	}
}



void StartMeasure(void)
{
	DS18X20_start_meas(DS18X20_POWER_EXTERN, 0);
	OS_AddTask(ReadMeasure, 700, 0);
}

void ReadMeasure(void) 
{
	if(sensorInside.present)
		DS18X20_read_meas(&gSensorIDs[sensorInside.index][0], resultMeasureInside);
	if(sensorOutside.present)
		DS18X20_read_meas(&gSensorIDs[sensorOutside.index][0], resultMeasureOutside);
	if(sensorCooland.present)
		DS18X20_read_meas(&gSensorIDs[sensorCooland.index][0], resultMeasureCoolant);
	OS_AddTask(StartMeasure, 5000, 0);
}

void LedBlink1(void)
{
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}

void LedBlink2(void)
{
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	if (ticksBlink == 0) 
		ticksBlink = 1;
	else ticksBlink = 0;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
