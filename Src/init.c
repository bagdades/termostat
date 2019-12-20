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
#include <string.h>

const char *dayOfWeek[7] = {
		"Íä.",
		"Ïí.",
		"Âò.",
		"Ñð.",
		"×ò.",
		"Ïò.",
		"Ñá."
	};

int16_t settedComfortTemp = 210;
int16_t settedWorkTimeTemp = 170;
int16_t settedSleepTimeTemp = 180;

RTC_TimeTypeDef workTimeStart;
RTC_TimeTypeDef workTimeStop;
RTC_TimeTypeDef sleepTimeStart;
RTC_TimeTypeDef sleepTimeStop;

uint8_t aShowSetSleepTime[20] = {0};
uint8_t aShowSetWorkTime[20] = {0};
uint8_t workDaysOfWeek[7] = {0, 1, 1, 1, 1, 1, 0};

extern RTC_HandleTypeDef hrtc;
extern const tFont* fontMenu;
extern const tFont* fontDigital;
const tFont* bigFont;
extern stateElement startState;
extern stateElement settingState;
extern stateElement setWorkDays;
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
extern stateData_t setSundayData;
extern stateData_t setMondayData;
extern stateData_t setTuesdayData;
extern stateData_t setWednesdayData;
extern stateData_t setThursdayData;
extern stateData_t setFridayData;
extern stateData_t setSaturdayData;
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;
extern const char *modeWorkText[3];
extern uint8_t modeWorkVar;

void InitMain(void)
{
	uint8_t saveBuf[21];
	HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0, I2C_MEMADD_SIZE_16BIT, saveBuf, sizeof(saveBuf), HAL_MAX_DELAY);
	workTimeStart.Hours = saveBuf[0];
	workTimeStart.Minutes = saveBuf[1];
	workTimeStop.Hours = saveBuf[2];
	workTimeStop.Minutes = saveBuf[3];
	sleepTimeStart.Hours = saveBuf[4];
	sleepTimeStart.Minutes = saveBuf[5];
	sleepTimeStop.Hours = saveBuf[6];
	sleepTimeStop.Minutes = saveBuf[7];
	settedComfortTemp = (int16_t)(saveBuf[9] << 8);
	settedComfortTemp |= saveBuf[8];
	settedSleepTimeTemp = (int16_t)(saveBuf[11] << 8);
	settedSleepTimeTemp |= saveBuf[10];
	settedWorkTimeTemp = (int16_t)saveBuf[13] << 8;
	settedWorkTimeTemp |= saveBuf[12];
	setSundayData.flag = saveBuf[14];
	setMondayData.flag = saveBuf[15];
	setTuesdayData.flag = saveBuf[16];
	setWednesdayData.flag = saveBuf[17];
	setThursdayData.flag = saveBuf[18];
	setFridayData.flag = saveBuf[19];
	setSaturdayData.flag = saveBuf[20];
	/* modeWorkVar */
	/* workTimeStart.Hooours */
	/* workTimeStart.Minutes */
	/* workTimeStop.Hours */
	/* workTimeStop.Minutes */
	/* sleepTimeStart.Hours */
	/* sleepTimeStart.Minutes */
	/* sleepTimeStop.Hours */
	/* sleepTimeStop.Minutes */
	/* settedComfortTemp */
	/* settedSleepTimeTemp */
	/* settedWorkTimeTemp */
	/* setSundayData.flag = workDaysOfWeek[0]; */
	/* setMondayData.flag = workDaysOfWeek[1]; */
	/* setTuesdayData.flag = workDaysOfWeek[2]; */
	/* setWednesdayData.flag = workDaysOfWeek[3]; */
	/* setThursdayData.flag = workDaysOfWeek[4]; */
	/* setFridayData.flag = workDaysOfWeek[5]; */
	/* setSaturdayData.flag = workDaysOfWeek[6]; */
	fontMenu = &Arial7;	
	fontDigital = &Arial9_b;
	bigFont = &Font;

	CurrState = (stateElement*)&startState;

	/* workTimeStart.Hours = 8; */
	/* workTimeStart.Minutes = 0; */
	/* workTimeStop.Hours = 16; */
	/* workTimeStop.Minutes = 0; */
	sprintf((char*)aShowSetWorkTime, "%02d:%02d - %02d:%02d", workTimeStart.Hours, workTimeStart.Minutes, workTimeStop.Hours, workTimeStop.Minutes);

	/* sleepTimeStart.Hours = 23; */
	/* sleepTimeStart.Minutes = 0; */
	/* sleepTimeStop.Hours = 6; */
	/* sleepTimeStop.Minutes = 0; */
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

	setWorkTempItemData.data = (int16_t*) &settedComfortTemp;
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

	setSundayData.text = "0";
	setMondayData.text = "1";
	setTuesdayData.text = "2";
	setWednesdayData.text = "3";
	setThursdayData.text = "4";
	setFridayData.text = "5";
	setSaturdayData.text = "6";

	setSundayData.data = &workDaysOfWeek;
	setMondayData.data = &workDaysOfWeek;
	setTuesdayData.data = &workDaysOfWeek;
	setWednesdayData.data = &workDaysOfWeek;
	setThursdayData.data = &workDaysOfWeek;
	setFridayData.data = &workDaysOfWeek;
	setSaturdayData.data = &workDaysOfWeek;

	/* setSundayData.flag = workDaysOfWeek[0]; */
	/* setMondayData.flag = workDaysOfWeek[1]; */
	/* setTuesdayData.flag = workDaysOfWeek[2]; */
	/* setWednesdayData.flag = workDaysOfWeek[3]; */
	/* setThursdayData.flag = workDaysOfWeek[4]; */
	/* setFridayData.flag = workDaysOfWeek[5]; */
	/* setSaturdayData.flag = workDaysOfWeek[6]; */
}

void Termostat(void)
{
}

int16_t TermGetWorkTemp(void)
{
	RTC_TimeTypeDef time;	
	uint16_t timeWorkStart, timeWorkStop, timeSleepStart, timeSleepStop;
	uint16_t timeCurr;
	uint8_t weekDay;
	mRTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);
	weekDay = mRTC_GetWeekDay(&hrtc);
	timeCurr = (((uint16_t)time.Hours) << 8) | time.Minutes;
	timeWorkStart = (((uint16_t)workTimeStart.Hours) << 8) | workTimeStart.Minutes;
	timeWorkStop = (((uint16_t)workTimeStop.Hours) << 8) | workTimeStop.Minutes;
	timeSleepStart = (((uint16_t)sleepTimeStart.Hours) << 8) | sleepTimeStart.Minutes;
	timeSleepStop = (((uint16_t)sleepTimeStop.Hours) << 8) | sleepTimeStop.Minutes;
	if (modeWorkVar == AUTO_MODE_WORK) 
	{
		if (timeCurr >= timeWorkStart && timeCurr < timeWorkStop && workDaysOfWeek[weekDay]) 
			return settedWorkTimeTemp;
		else if (timeCurr >= timeSleepStart || timeCurr < timeSleepStop) 
			return settedSleepTimeTemp;
		else return settedComfortTemp;
	}
	return settedComfortTemp;
}

void WriteEepromValue(void)
{
	uint8_t saveBuf[21];
	saveBuf[0] = workTimeStart.Hours;
	saveBuf[1] = workTimeStart.Minutes;
	saveBuf[2] = workTimeStop.Hours;
	saveBuf[3] = workTimeStop.Minutes;
	saveBuf[4] = sleepTimeStart.Hours;
	saveBuf[5] = sleepTimeStart.Minutes;
	saveBuf[6] = sleepTimeStop.Hours;
	saveBuf[7] = sleepTimeStop.Minutes;
	saveBuf[8] = settedComfortTemp;
	saveBuf[9] = settedComfortTemp >> 8;
	saveBuf[10] = settedSleepTimeTemp;
	saveBuf[11] = settedSleepTimeTemp >> 8;
	saveBuf[12] = settedWorkTimeTemp;
	saveBuf[13] = settedWorkTimeTemp >> 8;
	saveBuf[14] = setSundayData.flag;
	saveBuf[15] = setMondayData.flag;
	saveBuf[16] = setTuesdayData.flag;
	saveBuf[17] = setWednesdayData.flag;
	saveBuf[18] = setThursdayData.flag;
	saveBuf[19] = setFridayData.flag;
	saveBuf[20] = setSaturdayData.flag;
	HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0, I2C_MEMADD_SIZE_16BIT, saveBuf, sizeof(saveBuf), HAL_MAX_DELAY);
	while(HAL_I2C_IsDeviceReady(&hi2c1, 0xA0, 1, HAL_MAX_DELAY) != HAL_OK);
}
