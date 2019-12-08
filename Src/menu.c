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
stateData_t setHourData;
stateData_t setMinData;
stateData_t setSecData;
stateData_t setDayData;
stateData_t setMonthData;
stateData_t setYearData;

/* stateElement* startState; */

MAKE_STATE(startState, NULL_ENTRY, NULL_ENTRY, NULL_ENTRY, modeWork, ChangePrev, ChangeNext, ChangeParent, ChangeChild, ShowLcdMain, NULL_DATA, "Налаштування.");
MAKE_STATE(modeWork, settingTime, NULL_ENTRY, startState, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Режим роботи");
MAKE_STATE(settingTime, settingTemp, modeWork, startState, setTime, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Час. Дата.");
MAKE_STATE(settingTemp, settingSensors, settingTime, startState, setTempWorkTime, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Температура.");
MAKE_STATE(settingSensors, NULL_ENTRY, settingTemp, startState, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Сенсори");

MAKE_STATE(setTempWorkTime, setTempSleepTime, NULL_ENTRY, settingTemp, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Робочий час");
MAKE_STATE(setTempSleepTime, NULL_ENTRY, setTempWorkTime, settingTemp, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Сонний час");

MAKE_STATE(setTime, setDate, NULL_ENTRY, settingTime, setHour, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Час");

MAKE_STATE(setHour, setMin, NULL_ENTRY, setTime, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setHourData, "0G01");
MAKE_STATE(setMin, setSec, setHour, setTime, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setMinData, "1k34");
MAKE_STATE(setSec, setHour, setMin, setTime, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setSecData, "2067");

MAKE_STATE(setDate, setSleepTime, setTime, settingTime, setDay, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Дата");

MAKE_STATE(setDay, setMonth, NULL_ENTRY, setDate, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setDayData, "3O01");
MAKE_STATE(setMonth, setYear, setDay, setDate, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setMonthData, "4<34");
MAKE_STATE(setYear, setDay, setMonth, setDate, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setYearData, "5X67");
/* MAKE_STATE(setYear, setDay, setMonth, setDate, NULL_ENTRY, KeySetUpTimeDate, KeySetDownTimeDate, ChangeParent, ChangeNext, LcdSetClock, &setYearData, "5X89"); */

MAKE_STATE(setSleepTime, setWorkTime, setDate, settingTime, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Сонний час");
MAKE_STATE(setWorkTime, setWorkDays, setSleepTime, settingTime, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Робочий час");
MAKE_STATE(setWorkDays, setHoliDays, setWorkTime, settingTime, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Робочі дні тиждня");
MAKE_STATE(setHoliDays, NULL_ENTRY, setWorkDays, settingTime, NULL_ENTRY, ChangePrev, ChangeNext, ChangeParent, ChangeChild, LcdMenuList, NULL_DATA, "Святкові дні");

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

