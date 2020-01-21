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
const char sensorWaitConnect[] = "Conn. sensor & press ok";
const char sensorNotConnect[] = "No sensors";

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
const tFont* bigFont;

extern RTC_HandleTypeDef hrtc;
extern const tFont* fontMenu;
extern const tFont* fontDigital;
extern stateElement startState;
extern stateElement settingState;
extern stateElement setWorkDays;
extern uint8_t aShowTime[TIME_BUFFER_LENGTH];
extern uint8_t aShowDate[DATE_BUFFER_LENGTH];
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;
extern const char *modeWorkText[3];
extern uint8_t modeWorkVar;
extern uint8_t gSensorIDs[MAXSENSORS][OW_ROMCODE_SIZE];
extern uint8_t nSensors;
extern char variableChar[];
extern char owIDString[MAXSENSORS][17];


extern sensorData_t sensorInside;
extern sensorData_t sensorOutside;
extern sensorData_t sensorCooland;
uint8_t numStoredSensors = 0;

void InitMain(void)
{
	uint8_t saveBuf[22];
	uint8_t i;
	HAL_I2C_Mem_Read(&hi2c1, 0xA0, I2C_ADDR_SAVE_EEPROM, I2C_MEMADD_SIZE_16BIT, saveBuf, sizeof(saveBuf), HAL_MAX_DELAY);
	while(HAL_I2C_IsDeviceReady(&hi2c1, 0xA0, 1, HAL_MAX_DELAY) != HAL_OK);
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
	numStoredSensors = saveBuf[21];
	fontMenu = &Arial7;	
	fontDigital = &Arial9_b;
	bigFont = &Font;
	CurrState = (stateElement*)&startState;
	sprintf((char*)aShowSetWorkTime, "%02d:%02d - %02d:%02d", workTimeStart.Hours, workTimeStart.Minutes, workTimeStop.Hours, workTimeStop.Minutes);
	sprintf((char*)aShowSetSleepTime, "%02d:%02d - %02d:%02d", sleepTimeStart.Hours, sleepTimeStart.Minutes, sleepTimeStop.Hours, sleepTimeStop.Minutes);

	setTimeData.data = (uint8_t*) aShowTime;
	setTimeData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING;
	setTimeData.font = &fontDigital;

	setDateData.data = (uint8_t*) aShowDate;
	setDateData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING;
	setDateData.font = &fontDigital;

	setModeWorkData.data = (char*)modeWorkText[modeWorkVar];
	setModeWorkData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING;
	setModeWorkData.font = &fontMenu;

	setWorkTempItemData.data = (int16_t*) &settedComfortTemp;
	setWorkTempItemData.flag = MENU_ITEM_SETTING | COMMA;
	setWorkTempItemData.font = &fontDigital;

	setWorkTimeTempData.data = (int16_t*) &settedWorkTimeTemp;
	setWorkTimeTempData.flag = MENU_ITEM_SETTING | COMMA;
	setWorkTimeTempData.font = &fontDigital;

	setSleepTimeTempData.data = (int16_t*) &settedSleepTimeTemp;
	setSleepTimeTempData.flag = MENU_ITEM_SETTING | COMMA;
	setSleepTimeTempData.font = &fontDigital;

	setSleepTimeBoundary.data = (uint8_t*) aShowSetSleepTime;
	setSleepTimeBoundary.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING;
	setSleepTimeBoundary.font = &fontDigital;

	setWorkTimeBoundary.data = (uint8_t*) aShowSetWorkTime;
	setWorkTimeBoundary.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING;
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

	insideTempItemData.font = &fontMenu;
	insideTempItemData.flag = MENU_ITEM_TEXT;
	insideTempItemData.data = (char*)sensorWaitConnect;
	outsideTempItemData.font = &fontMenu;
	outsideTempItemData.flag = MENU_ITEM_TEXT;
	outsideTempItemData.data = (char*)sensorWaitConnect;
	coolantTempItemData.font = &fontMenu;
	coolantTempItemData.flag = MENU_ITEM_TEXT;
	coolantTempItemData.data = (char*)sensorWaitConnect;
	insideTempItemData.text = owIDString[0];
	outsideTempItemData.text = owIDString[1];
	coolantTempItemData.text = owIDString[2];

	uint8_t j;
	for (i = 0; i < MAXSENSORS; ++i) {
		HAL_I2C_Mem_Read(&hi2c1, 0xA0, I2C_ADDR_INSIDE_SENSOR_CODE + (i * OW_ROMCODE_SIZE), I2C_MEMADD_SIZE_16BIT, saveBuf, OW_ROMCODE_SIZE, HAL_MAX_DELAY);
		switch (i) 
		{
			case 0:
				for (j = 0; j < OW_ROMCODE_SIZE; j++) {
					sensorInside.ID[j] = saveBuf[j];
				}
				sensorInside.index = DS18X20_searchID(gSensorIDs, sensorInside.ID);
				if(sensorInside.index != DS18X20_NO_SENSOR)
					sensorInside.present = TRUE;
				break;
			case 1:
				for (j = 0; j < OW_ROMCODE_SIZE; j++) {
					sensorOutside.ID[j] = saveBuf[j];
				}
				sensorOutside.index = DS18X20_searchID(gSensorIDs, sensorOutside.ID);
				if(sensorOutside.index != DS18X20_NO_SENSOR)
					sensorOutside.present = TRUE;
				break;
			case 2:
				for (j = 0; j < OW_ROMCODE_SIZE; j++) {
					sensorCooland.ID[j] = saveBuf[j];
				}
				sensorCooland.index = DS18X20_searchID(gSensorIDs, sensorCooland.ID);
				if(sensorCooland.index != DS18X20_NO_SENSOR)
					sensorCooland.present = TRUE;
				break;
			default:
				break;
		}
	}
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
	else if(modeWorkVar == OFF_MODE_WORK)
		return 0;
	return settedComfortTemp;
}

void WriteEepromValue(void)
{
	uint8_t saveBuf[22];
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
	saveBuf[21] = numStoredSensors;
	HAL_I2C_Mem_Write(&hi2c1, 0xA0, I2C_ADDR_SAVE_EEPROM, I2C_MEMADD_SIZE_16BIT, saveBuf, sizeof(saveBuf), HAL_MAX_DELAY);
	while(HAL_I2C_IsDeviceReady(&hi2c1, 0xA0, 1, HAL_MAX_DELAY) != HAL_OK);
}

void WriteEepromSensor(uint8_t addr)
{
	uint8_t i;
	uint8_t sBuf[OW_ROMCODE_SIZE];
	for (i = 0; i < OW_ROMCODE_SIZE; i++) {
		sBuf[i] = gSensorIDs[0][i];
	}
	HAL_I2C_Mem_Write(&hi2c1, 0xA0, addr, I2C_MEMADD_SIZE_16BIT, sBuf, OW_ROMCODE_SIZE, HAL_MAX_DELAY);
	while (HAL_I2C_IsDeviceReady(&hi2c1, 0xA0, 1, HAL_MAX_DELAY) != HAL_OK); 
}
