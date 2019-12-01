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

extern const tFont* fontMenu;
extern const tFont* fontDigital;
extern stateElement startState;
extern stateElement settingState;
extern stateData_t setMonthData;
extern stateData_t setYearData;
extern uint8_t aShowTime[TIME_BUFFER_LENGTH];
extern uint8_t aShowDate[DATE_BUFFER_LENGTH];
extern stateData_t timeData;
extern stateData_t dateData;
extern stateData_t setHourData;
extern stateData_t setMinData;
extern stateData_t setSecData;
extern stateData_t setDayData;
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;

void InitMain(void)
{
	fontMenu = &Arial7;	
	fontDigital = &Arial9_b;
	CurrState = (stateElement*)&startState;

	setHourData.data = (uint8_t*) aShowTime;
	setHourData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | TIME_BUFFER_LENGTH;
	setHourData.font = &fontDigital;

	setMinData.data = (uint8_t*) aShowTime;
	setMinData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | TIME_BUFFER_LENGTH;
	setMinData.font = &fontDigital;

	setSecData.data = (uint8_t*) aShowTime;
	setSecData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | TIME_BUFFER_LENGTH;
	setSecData.font = &fontDigital;

	setDayData.data = (uint8_t*) aShowDate;
	setDayData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | DATE_BUFFER_LENGTH;
	setDayData.font = &fontDigital;

	setMonthData.data = (uint8_t*) aShowDate;
	setMonthData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | DATE_BUFFER_LENGTH;
	setMonthData.font = &fontDigital;

	setYearData.data = (uint8_t*) &aShowDate;
	setYearData.flag = MENU_ITEM_TEXT | MENU_ITEM_SETTING | DATE_BUFFER_LENGTH;
	setYearData.font = &fontDigital;
}
