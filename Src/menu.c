/*
 * menu.c
 *
 *  Created on: 25 вер. 2012
 *      Author: vovan
 */

#include "menu.h"

stateElement NullState={(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0,(stateData_t*)0, {0x00}};
stateElement* CurrState;

stateData_t timeData;
stateData_t dateData;
stateData_t setTimeData;
stateData_t setDateData;
stateData_t setModeWorkData;
stateData_t setWorkTempItemData;
stateData_t setWorkTimeTempData;
stateData_t setSleepTimeTempData;
stateData_t setSleepTimeBoundary;
stateData_t setWorkTimeBoundary;

extern const char *modeWorkText[2];
extern uint8_t modeWorkVar;
/* stateElement* startState; */

MAKE_STATE(startState, startSetTemp, NULL_ENTRY, NULL_ENTRY, modeWork, ChangeNext, ChangeNext, ChangeParent, ChangeChild, ShowLcdMain, NULL_DATA, "Налаштування.");
/* Set temperature from main screen */
MAKE_STATE(startSetTemp, NULL_ENTRY, startState, NULL_ENTRY, NULL_ENTRY, KeySetUpVar, KeySetDownVar, ChangePrev, ChangeChild, LcdDrawOneItem, &setWorkTempItemData, "Температура");
/*========================================================================================*/
MAKE_STATE(modeWork, settingTime, NULL_ENTRY, startState, setModeWork, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Режим роботи");
/* Set mode work */
MAKE_STATE(setModeWork, NULL_ENTRY, NULL_ENTRY, modeWork, NULL_ENTRY, KeySetModeWork, KeySetModeWork, ChangeParent, ChangeChild, LcdDrawOneItem, &setModeWorkData, NULL_TEXT);
/*========================================================================================*/
MAKE_STATE(settingTime, settingTemp, modeWork, startState, setTime, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Час. Дата.");
/*========================================================================================*/
MAKE_STATE(setTime, setDate, NULL_ENTRY, settingTime, setHour, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Час");
/* Set time */
MAKE_STATE(setHour, setMin, NULL_ENTRY, setTime, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setTimeData, "0G01");
MAKE_STATE(setMin, setSec, setHour, setTime, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setTimeData, "1k34");
MAKE_STATE(setSec, setHour, setMin, setTime, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setTimeData, "2067");
/*========================================================================================*/
MAKE_STATE(setDate, setSleepTime, setTime, settingTime, setDay, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Дата");
/* Set date */
MAKE_STATE(setDay, setMonth, NULL_ENTRY, setDate, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setDateData, "3O01");
MAKE_STATE(setMonth, setYear, setDay, setDate, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setDateData, "4<34");
MAKE_STATE(setYear, setDay, setMonth, setDate, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setDateData, "5X67");
/* MAKE_STATE(setYear, setDay, setMonth, setDate, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setYearData, "5X89"); */
/*========================================================================================*/
MAKE_STATE(setSleepTime, setWorkTime, setDate, settingTime, setSleepTimeStartHour, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Сонний час");
MAKE_STATE(setSleepTimeStartHour, setSleepTimeStartMinute, setSleepTimeStopMinute, setSleepTime, NULL_ENTRY, KeySetUpBoundTime, KeySetDownBoundTime, ChangeParent, ChangeNext, LcdDrawOneItem, &setSleepTimeBoundary, "0G01");
MAKE_STATE(setSleepTimeStartMinute, setSleepTimeStopHour, setSleepTimeStartHour, setSleepTime, NULL_ENTRY, KeySetUpBoundTime, KeySetDownBoundTime, ChangeParent, ChangeNext, LcdDrawOneItem, &setSleepTimeBoundary, "1k34");
MAKE_STATE(setSleepTimeStopHour, setSleepTimeStopMinute, setSleepTimeStartMinute, setSleepTime, NULL_ENTRY, KeySetUpBoundTime, KeySetDownBoundTime, ChangeParent, ChangeNext, LcdDrawOneItem, &setSleepTimeBoundary, "3G89");
MAKE_STATE(setSleepTimeStopMinute, setSleepTimeStartHour, setSleepTimeStopHour, setSleepTime, NULL_ENTRY, KeySetUpBoundTime, KeySetDownBoundTime, ChangeParent, ChangeNext, LcdDrawOneItem, &setSleepTimeBoundary, "4k;<");
/*========================================================================================*/
MAKE_STATE(setWorkTime, setWorkDays, setSleepTime, settingTime, setWorkTimeStartHour, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Робочий час");
MAKE_STATE(setWorkTimeStartHour, setWorkTimeStartMinute, setWorkTimeStopMinute, setWorkTime, NULL_ENTRY, KeySetUpBoundTime, KeySetDownBoundTime, ChangeParent, ChangeNext, LcdDrawOneItem, &setWorkTimeBoundary, "0G01");
MAKE_STATE(setWorkTimeStartMinute, setWorkTimeStopHour, setWorkTimeStartHour, setWorkTime, NULL_ENTRY, KeySetUpBoundTime, KeySetDownBoundTime, ChangeParent, ChangeNext, LcdDrawOneItem, &setWorkTimeBoundary, "1k34");
MAKE_STATE(setWorkTimeStopHour, setWorkTimeStopMinute, setWorkTimeStartMinute, setWorkTime, NULL_ENTRY, KeySetUpBoundTime, KeySetDownBoundTime, ChangeParent, ChangeNext, LcdDrawOneItem, &setWorkTimeBoundary, "3G89");
MAKE_STATE(setWorkTimeStopMinute, setWorkTimeStartHour, setWorkTimeStopHour, setWorkTime, NULL_ENTRY, KeySetUpBoundTime, KeySetDownBoundTime, ChangeParent, ChangeNext, LcdDrawOneItem, &setWorkTimeBoundary, "4k;<");
/*========================================================================================*/
MAKE_STATE(setWorkDays, NULL_ENTRY, setWorkTime, settingTime, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Робочі дні тиждня");
/* MAKE_STATE(setHoliDays, NULL_ENTRY, setWorkDays, settingTime, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Святкові дні"); */

MAKE_STATE(settingTemp, settingSensors, settingTime, startState, setWorkTemp, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Температура.");
/*========================================================================================*/
MAKE_STATE(setWorkTemp, setTempWorkTime, NULL_ENTRY, settingTemp, setWorkTempItem, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Робоча температура");
/* Set work temperatre */
MAKE_STATE(setWorkTempItem, NULL_ENTRY, NULL_ENTRY, setWorkTemp, NULL_ENTRY, KeySetUpVar, KeySetDownVar, ChangeParent, ChangeChild, LcdDrawOneItem, &setWorkTempItemData, NULL_TEXT);
/* Set temperature for work time */
MAKE_STATE(setTempWorkTime, setTempSleepTime, setWorkTemp, settingTemp, setWorkTimeTempItem, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Робочий час");
MAKE_STATE(setWorkTimeTempItem, NULL_ENTRY, NULL_ENTRY, setTempWorkTime, NULL_ENTRY, KeySetUpVar, KeySetDownVar, ChangeParent, ChangeChild, LcdDrawOneItem, &setWorkTimeTempData , NULL_TEXT);
/* Set temperature for sleep time */
MAKE_STATE(setTempSleepTime, NULL_ENTRY, setTempWorkTime, settingTemp, setSleepTimeTempItem, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Сонний час");
MAKE_STATE(setSleepTimeTempItem, NULL_ENTRY, NULL_ENTRY, setTempSleepTime, NULL_ENTRY, KeySetUpVar, KeySetDownVar, ChangeParent, ChangeChild, LcdDrawOneItem, &setSleepTimeTempData, NULL_TEXT);
/*========================================================================================*/
MAKE_STATE(settingSensors, NULL_ENTRY, settingTemp, startState, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Сенсори");

void ChangeState(stateElement* NewState){
	if((void*)NewState==(void*)&(NullState))
		return;
	CurrState=NewState;
}
void ChangeNext(void){
	ChangeState(NEXT);
}
void ChangePrev(void){
	ChangeState(PREVIOUS);
}
void ChangeParent(void){
	ChangeState(PARENT);
	}
void ChangeChild(void){
	ChangeState(CHILD);
}

