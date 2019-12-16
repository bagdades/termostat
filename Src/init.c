/*
 * =====================================================================================
 *
 *       Filename:  init.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.11.19 22:46:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  vovan (), volodumurkoval0@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */



#include "init.h"
#include <stdio.h>

int16_t settedWorkTemp = 210;
int16_t settedWorkTimeTemp = 170;
int16_t settedSleepTimeTemp = 180;

RTC_TimeTypeDef workTimeStart;
RTC_TimeTypeDef workTimeStop;
RTC_TimeTypeDef sleepTimeStart;
RTC_TimeTypeDef sleepTimeStop;

uint8_t aShowSetSleepTime[15] = {0};
uint8_t aShowSetWorkTime[15] = {0};

extern RTC_HandleTypeDef hrtc;
extern const tFont* fontMenu;
extern const tFont* fontDigital;
const tFont* bigFont;
extern stateElement startState;
extern stateElement settingState;
extern uint8_t aShowTime[TIME_BUFFER_LENGTH];
extern uint8_t aShowDate[DATE_BUFFER_LENGTH];
extern stateData_t timeData;
extern stateData_t dateData;
extern stateData_t setTimeData;
extern stateData_t setDateData;
extern stateData_t setModeWorkData;
extern stateData_t setWorkTempItemData;
extern stateData_t setWorkTimeTempData;
extern stateData_t setSleepTimeTempData;
extern stateData_t setSleepTimeBoundary;
extern stateData_t setWorkTimeBoundary;
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;
extern const char *modeWorkText[2];
extern uint8_t modeWorkVar;

void InitMain(void)
{
	fontMenu = &Arial7;	
	fontDigital = &Arial9_b;
	bigFont = &Font;

	CurrState = (stateElement*)&startState;

	workTimeStart.Hours = 8;
	workTimeStart.Minutes = 0;
	workTimeStop.Hours = 16;
	workTimeStop.Minutes = 0;
	sprintf((char*)aShowSetWorkTime, "%02d:%02d - %02d:%02d", workTimeStart.Hours, workTimeStart.Minutes, workTimeStop.Hours, workTimeStop.Minutes);

	sleepTimeStart.Hours = 23;
	sleepTimeStart.Minutes = 0;
	sleepTimeStop.Hours = 6;
	sleepTimeStop.Minutes = 0;
	sprintf((char*)aShowSetSleepTime, "%02d:%02d - %02d:%02d", sleepTimeStart.Hours, sleepTimeStart.Minutes, sleepTimeStop.Hours, sleepTimeStop.Minutes);


	setTimeData.data = (uint8_t*) aShowTime;
	setTimeData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | TIME_BUFFER_LENGTH;
	setTimeData.font = &fontDigital;

	setDateData.data = (uint8_t*) aShowDate;
	setDateData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | DATE_BUFFER_LENGTH;
	setDateData.font = &fontDigital;

	setModeWorkData.data = (char*)modeWorkText[modeWorkVar];
	setModeWorkData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | DATE_BUFFER_LENGTH;
	setModeWorkData.font = &fontMenu;

	setWorkTempItemData.data = (int16_t*) &settedWorkTemp;
	setWorkTempItemData.flag = MENU_ITEM_SETTING | DATE_BUFFER_LENGTH | COMMA;
	setWorkTempItemData.font = &fontDigital;

	setWorkTimeTempData.data = (int16_t*) &settedWorkTimeTemp;
	setWorkTimeTempData.flag = MENU_ITEM_SETTING | DATE_BUFFER_LENGTH | COMMA;
	setWorkTimeTempData.font = &fontDigital;

	setSleepTimeTempData.data = (int16_t*) &settedSleepTimeTemp;
	setSleepTimeTempData.flag = MENU_ITEM_SETTING | DATE_BUFFER_LENGTH | COMMA;
	setSleepTimeTempData.font = &fontDigital;

	setSleepTimeBoundary.data = (uint8_t*) aShowSetSleepTime;
	setSleepTimeBoundary.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | DATE_BUFFER_LENGTH;
	setSleepTimeBoundary.font = &fontDigital;

	setWorkTimeBoundary.data = (uint8_t*) aShowSetWorkTime;
	setWorkTimeBoundary.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | DATE_BUFFER_LENGTH;
	setWorkTimeBoundary.font = &fontDigital;
}

void Termostat(void)
{
}

int16_t TermGetWorkTemp(void)
{
	RTC_TimeTypeDef time;	
	uint16_t timeWorkStart, timeWorkStop, timeSleepStart, timeSleepStop;
	uint16_t timeCurr;
	mRTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);
	timeCurr = (((uint16_t)time.Hours) << 8) | time.Minutes;
	timeWorkStart = (((uint16_t)workTimeStart.Hours) << 8) | workTimeStart.Minutes;
	timeWorkStop = (((uint16_t)workTimeStop.Hours) << 8) | workTimeStop.Minutes;
	timeSleepStart = (((uint16_t)sleepTimeStart.Hours) << 8) | sleepTimeStart.Minutes;
	timeSleepStop = (((uint16_t)sleepTimeStop.Hours) << 8) | sleepTimeStop.Minutes;
	if (modeWorkVar == AUTO_MODE_WORK) 
	{
		if (timeCurr >= timeWorkStart && timeCurr < timeWorkStop) 
			return settedWorkTimeTemp;
		else if (timeCurr >= timeSleepStart || timeCurr < timeSleepStop) 
				return settedSleepTimeTemp;
		else return settedWorkTemp;
	}
	return settedWorkTemp;
}
