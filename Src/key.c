/*
 * key.c
 *
 *  Created on: 25 вер. 2012
 *      Author: vovan
 */

#include "key.h"
#include <stdio.h>
/* #include "menu.h" */

extern stateElement startState;
extern stateElement setDay;
extern stateElement startSetTemp;
extern stateElement setWorkTime;
extern stateElement setSleepTime;
extern stateElement setWorkDays;
extern uint8_t workDaysOfWeek[7];
extern uint8_t aShowTime[TIME_BUFFER_LENGTH];
extern uint8_t aShowDate[DATE_BUFFER_LENGTH];
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;
extern RTC_HandleTypeDef hrtc;
extern uint8_t modeWorkVar;
extern stateData_t setModeWorkData;
extern const char *modeWorkText[2];
extern int16_t settedComfortTemp;
extern RTC_TimeTypeDef workTimeStart;
extern RTC_TimeTypeDef workTimeStop;
extern RTC_TimeTypeDef sleepTimeStart;
extern RTC_TimeTypeDef sleepTimeStop;
extern uint8_t aShowSetSleepTime[];
extern uint8_t aShowSetWorkTime[];
extern const char sensorWaitConnect[];
extern const char sensorNotConnect[];
extern uint8_t gSensorIDs[MAXSENSORS][OW_ROMCODE_SIZE];
extern char owIDString[MAXSENSORS][17];
uint8_t keyPressed;
/**
 * @name KeyInit
 * Initialisation key
 */
/* void KeyInit(void){ */
/* 	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; //Enable clock portA */
/* 	 */
/* 	GPIOB->CRL &= ~(((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << KEY_OK * 4) | */
/* 					((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << KEY_RIGHT * 4) | */
/* 					((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << KEY_LEFT * 4) | */
/* 					((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << KEY_DOWN * 4) | */
/* 					((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << KEY_UP * 4));	//Reset configuration */
/* 	GPIOB->CRL |= ((GPIO_CRL_CNF0_1 << KEY_OK * 4) | */
/* 					(GPIO_CRL_CNF0_1 << KEY_RIGHT * 4) | */
/* 					(GPIO_CRL_CNF0_1 << KEY_LEFT * 4) | */
/* 					(GPIO_CRL_CNF0_1 << KEY_DOWN * 4) | */
/* 					(GPIO_CRL_CNF0_1 << KEY_UP * 4));						//All-> input, pull-up */
/* 	GPIOB->BSRR |= (1 << KEY_OK) | (1 << KEY_RIGHT) | (1 << KEY_LEFT) | (1 << KEY_DOWN) | (1 << KEY_UP);//Pull-up */
/* } */

void KeyScan(void)
{
	int8_t key;
	static uint8_t temp = 0;
	if (HAL_GPIO_ReadPin(KEY_UP_GPIO_Port, KEY_UP_Pin) == 0)
		key = _UP;
	else if (HAL_GPIO_ReadPin(KEY_DOWN_GPIO_Port, KEY_DOWN_Pin) == 0)
		key = _DOWN;
	else if (HAL_GPIO_ReadPin(KEY_LEFT_GPIO_Port, KEY_LEFT_Pin) == 0)
		key = _LEFT;
	else if (HAL_GPIO_ReadPin(KEY_RIGHT_GPIO_Port, KEY_RIGHT_Pin) == 0)
		key = _RIGHT;
	else
		key = 0;
	if (key) {
		if (temp >= DELAY_LONG) {
			temp = DELAY_LONG - 1;
			keyPressed = key;
			return;
		}
		if (temp == DELAY_SHORT)
			keyPressed = key;
		temp++;
		return;
	} else
		temp = 0;
}
void KeyHand(void) {
	FuncPtr pFunc;
	KeyScan();
	if (keyPressed) {
		switch (keyPressed) {
		case _UP:
			keyPressed = 0;
			pFunc = CurrState->HandUp;
			if (pFunc == (void*) 0)
				break;
			pFunc();
			break;
		case _DOWN:
			keyPressed = 0;
			pFunc = CurrState->HandDown;
			if (pFunc == (void*) 0)
				break;
			pFunc();
			break;
		case _LEFT:
			keyPressed = 0;
			pFunc = CurrState->HandLeft;
			if (pFunc == (void*) 0)
				break;
			pFunc();
			break;
		case _RIGHT:
			keyPressed = 0;
			pFunc = CurrState->HandRight;
			if (pFunc == (void*) 0)
				break;
			pFunc();
			break;
		/* case _OK: */
		/* 	keyPressed = 0; */
			/* pFunc = (FuncPtr)(&CurrState->HandOk); */
			/* if (pFunc == (void*) 0) */
			/* 	break; */
			/* pFunc(); */
			/* break; */
		default:
			break;
		}
	}
}

void KeySetUpTimeDate(void) {
	uint8_t idx = CurrState->Text[0] - '0';
	uint8_t value = CurrState->Text[1] - '0';
	mRTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	mRTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	if (CurrState == (stateElement*) &setDay) {
		if (sDate.Month == 4 || sDate.Month == 6
				|| sDate.Month == 9 || sDate.Month == 11)
			value = 30;
		else if (sDate.Month == 2) {
			if (CheckLeap(sDate.Month))
				value = 29;
			else
				value = 28;
		} else
			value = 31;
	}
	switch (idx) 
	{
		case 0:
			if (sTime.Hours < value) 
				sTime.Hours++;
			else if(sTime.Hours >= value)
				sTime.Hours = 0;
			mRTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			sprintf((char*)aShowTime, "%.2d:%.2d:%.2d", sTime.Hours, sTime.Minutes, sTime.Seconds);
			break;
		case 1:
			if (sTime.Minutes < value) 
				sTime.Minutes++;
			else if(sTime.Minutes >= value)
				sTime.Minutes = 0;
			mRTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			sprintf((char*)aShowTime, "%.2d:%.2d:%.2d", sTime.Hours, sTime.Minutes, sTime.Seconds);
			break;
		case 2:
			if (sTime.Seconds < value) 
				sTime.Seconds++;
			else if(sTime.Seconds >= value)
				sTime.Seconds = 0;
			mRTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			sprintf((char*)aShowTime, "%.2d:%.2d:%.2d", sTime.Hours, sTime.Minutes, sTime.Seconds);
			break;
		case 3:
			if(sDate.Date < value)
				sDate.Date++;
			else if(sDate.Date >= value)
				sDate.Date = 1;
			mRTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
			sprintf((char*)aShowDate, "%.2d/%.2d/%.2d", sDate.Date, sDate.Month, sDate.Year);
			break;
		case 4:
			if(sDate.Month < value)
				sDate.Month++;
			else if(sDate.Month >= value)
				sDate.Month = 1;
			mRTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
			sprintf((char*)aShowDate, "%.2d/%.2d/%.2d", sDate.Date, sDate.Month, sDate.Year);
			break;
		case 5:
			if(sDate.Year < 99)
				sDate.Year++;
			else if(sDate.Year >= 99)
				sDate.Year = 1;
			mRTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
			sprintf((char*)aShowDate, "%.2d/%.2d/%.2d", sDate.Date, sDate.Month, sDate.Year);
			break;
		default:
			break;
	}
}

void KeySetDownTimeDate(void) {
	uint8_t idx = CurrState->Text[0] - '0';
	uint8_t value = CurrState->Text[1] - '0';
	mRTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	mRTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	if (CurrState == (stateElement*) &setDay) {
		if (sDate.Month == 4 || sDate.Month == 6
				|| sDate.Month == 9 || sDate.Month == 11)
			value = 30;
		else if (sDate.Month == 2) {
			if (CheckLeap(sDate.Year))
				value = 29;
			else
				value = 28;
		} else
			value = 31;
	}
	switch (idx) 
	{
		case 0:
			sTime.Hours--;
			if(sTime.Hours == 255)
				sTime.Hours = value;
			mRTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			sprintf((char*)aShowTime, "%.2d:%.2d:%.2d", sTime.Hours, sTime.Minutes, sTime.Seconds);
			break;
		case 1:
			sTime.Minutes--;
			if(sTime.Minutes == 255)
				sTime.Minutes = value;
			mRTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			sprintf((char*)aShowTime, "%.2d:%.2d:%.2d", sTime.Hours, sTime.Minutes, sTime.Seconds);
			break;
		case 2:
			sTime.Seconds--;
			if(sTime.Seconds == 255)
				sTime.Seconds = value;
			mRTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
			sprintf((char*)aShowTime, "%.2d:%.2d:%.2d", sTime.Hours, sTime.Minutes, sTime.Seconds);
			break;
		case 3:
			sDate.Date--;
			if(sDate.Date < 1)
				sDate.Date = value;
			mRTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
			sprintf((char*)aShowDate, "%.2d/%.2d/%.2d", sDate.Date, sDate.Month, sDate.Year);
			break;
		case 4:
			sDate.Month--;
			if(sDate.Month < 1)
				sDate.Month = value;
			mRTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
			sprintf((char*)aShowDate, "%.2d/%.2d/%.2d", sDate.Date, sDate.Month, sDate.Year);
			break;
		case 5:
			sDate.Year--;
			if(sDate.Year < 1)
				sDate.Year = 1;
			mRTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
			sprintf((char*)aShowDate, "%.2d/%.2d/%.2d", sDate.Date, sDate.Month, sDate.Year);
			break;
		default:
			break;
	}
}

void KeySetModeWork(void)
{
	if(modeWorkVar == OFF_MODE_WORK)	
		modeWorkVar = AUTO_MODE_WORK;
	else if(modeWorkVar == AUTO_MODE_WORK)
		modeWorkVar = MANUAL_MODE_WORK;
	else modeWorkVar = OFF_MODE_WORK;
	setModeWorkData.data = (char*)modeWorkText[modeWorkVar];
}

void KeySetUpVar(void)
{
	if(CurrState == &startSetTemp)
	{
		modeWorkVar = MANUAL_MODE_WORK;
		setModeWorkData.data = (char*)modeWorkText[modeWorkVar];
	}
	int16_t temp;
	temp = *(int16_t*)CurrState->data->data;
	temp++;
	*(int16_t*)CurrState->data->data = temp;
	OS_AddTask(WriteEepromValue, 3000, 0);
}

void KeySetDownVar(void)
{
	if(CurrState == &startSetTemp)
	{
		modeWorkVar = MANUAL_MODE_WORK;
		setModeWorkData.data = (char*)modeWorkText[modeWorkVar];
	}
	int16_t temp;
	temp = *(int16_t*)CurrState->data->data;
	temp--;
	*(int16_t*)CurrState->data->data = temp;
	OS_AddTask(WriteEepromValue, 3000, 0);
}

void KeySetUpBoundTime(void)
{
	uint8_t idx = CurrState->Text[0] - '0';
	uint8_t value = CurrState->Text[1] - '0';
	RTC_TimeTypeDef* sTimeStart;	
	RTC_TimeTypeDef* sTimeStop;
	uint8_t *aShowSetTime;
	if(CurrState->Parent == (void*)&setSleepTime)
	{
		sTimeStart = &sleepTimeStart;
		sTimeStop = &sleepTimeStop;
		aShowSetTime = aShowSetSleepTime;
	} 
	else if(CurrState->Parent == (void*)&setWorkTime)
	{
		sTimeStart = &workTimeStart;
		sTimeStop = &workTimeStop;
		aShowSetTime = aShowSetWorkTime;
	}
	else return;
	switch (idx) 
	{
		case 0:
			if (sTimeStart->Hours < value) 
				sTimeStart->Hours++;
			else if(sTimeStart->Hours >= value)
				sTimeStart->Hours = 0;
			sprintf((char*)aShowSetTime, "%02d:%02d - %02d:%02d", sTimeStart->Hours, sTimeStart->Minutes, sTimeStop->Hours, sTimeStop->Minutes);
			break;
		case 1:
			if (sTimeStart->Minutes < value) 
				sTimeStart->Minutes++;
			else if(sTimeStart->Minutes >= value)
				sTimeStart->Minutes = 0;
			sprintf((char*)aShowSetTime, "%02d:%02d - %02d:%02d", sTimeStart->Hours, sTimeStart->Minutes, sTimeStop->Hours, sTimeStop->Minutes);
			break;
			case 3:
			if (sTimeStop->Hours < value) 
				sTimeStop->Hours++;
			else if(sTimeStop->Hours >= value)
				sTimeStop->Hours = 0;
			sprintf((char*)aShowSetTime, "%02d:%02d - %02d:%02d", sTimeStart->Hours, sTimeStart->Minutes, sTimeStop->Hours, sTimeStop->Minutes);
				break;
				case 4:
			if (sTimeStop->Minutes < value) 
				sTimeStop->Minutes++;
			else if(sTimeStop->Minutes >= value)
				sTimeStop->Minutes = 0;
			sprintf((char*)aShowSetTime, "%02d:%02d - %02d:%02d", sTimeStart->Hours, sTimeStart->Minutes, sTimeStop->Hours, sTimeStop->Minutes);
					break;
		default:
			break;
			
	}
	OS_AddTask(WriteEepromValue, 3000, 0);
}

void KeySetDownBoundTime(void)
{
	uint8_t idx = CurrState->Text[0] - '0';
	uint8_t value = CurrState->Text[1] - '0';
	RTC_TimeTypeDef* sTimeStart;	
	RTC_TimeTypeDef* sTimeStop;
	uint8_t *aShowSetTime;
	if(CurrState->Parent == (void*)&setSleepTime)
	{
		sTimeStart = &sleepTimeStart;
		sTimeStop = &sleepTimeStop;
		aShowSetTime = aShowSetSleepTime;
	} else {
		sTimeStart = &workTimeStart;
		sTimeStop = &workTimeStop;
		aShowSetTime = aShowSetWorkTime;
	}
	switch (idx) 
	{
		case 0:
			sTimeStart->Hours--;
			if(sTimeStart->Hours == 255)
				sTimeStart->Hours = value;
			sprintf((char*)aShowSetTime, "%02d:%02d - %02d:%02d", sTimeStart->Hours, sTimeStart->Minutes, sTimeStop->Hours, sTimeStop->Minutes);
			break;
		case 1:
			sTimeStart->Minutes--;
			if(sTimeStart->Minutes == 255)
				sTimeStart->Minutes = value;
			sprintf((char*)aShowSetTime, "%02d:%02d - %02d:%02d", sTimeStart->Hours, sTimeStart->Minutes, sTimeStop->Hours, sTimeStop->Minutes);
			break;
			case 3:
			sTimeStop->Hours--;
			if(sTimeStop->Hours == 255)
				sTimeStop->Hours = value;
			sprintf((char*)aShowSetTime, "%02d:%02d - %02d:%02d", sTimeStart->Hours, sTimeStart->Minutes, sTimeStop->Hours, sTimeStop->Minutes);
				break;
				case 4:
			sTimeStop->Minutes--;
			if(sTimeStop->Minutes == 255)
				sTimeStop->Minutes = value;
			sprintf((char*)aShowSetTime, "%02d:%02d - %02d:%02d", sTimeStart->Hours, sTimeStart->Minutes, sTimeStop->Hours, sTimeStop->Minutes);
					break;
		default:
			break;
			
	}
	OS_AddTask(WriteEepromValue, 3000, 0);
}

void KeyToogleState(void)
{
	uint8_t idx;
	if(CurrState->data == NULL_DATA)
		return;
	if (CurrState->Parent == (void*)&setWorkDays) 
	{
		idx = *CurrState->data->text - '0';
		if(CurrState->data->flag)
		{
			CurrState->data->flag = 0;
			workDaysOfWeek[idx] = 0;
		}
		else 
		{
			CurrState->data->flag = 1;
			workDaysOfWeek[idx] = 1;
		}
	}
	OS_AddTask(WriteEepromValue, 3000, 0);
}

uint8_t CheckLeap(uint8_t year) {
	uint16_t yearFull = 2000 + year;
	if ((yearFull % 400) == 0)
		return LEAP;
	else if ((yearFull % 100) == 0)
		return NOT_LEAP;
	else if ((yearFull % 4) == 0)
		return LEAP;
	else
		return NOT_LEAP;
}

void KeySearchSensor(void)
{
	uint8_t numSensor;
	numSensor = search_sensors();
	if (numSensor) 
	{
		CurrState->data->data = owIDString[0];
	}
	else CurrState->data->data = (char*)sensorNotConnect;
}
