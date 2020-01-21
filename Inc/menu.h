/*
 * menu.h
 *
 *  Created on: 25 вер. 2012
 *      Author: vovan
 */

#ifndef MENU_H_
#define MENU_H_

#include "main.h"
#include "lcdwg.h"
#include "key.h"

typedef void (*FuncPtr)(void);

typedef struct {
	/* біти 0-4 -> кількість символів
	 * біт 5 -> меню налаштувань
	 * біт 6 -> дані як текст 
	 * біт 7 -> присутність коми в значенні параметра
	 */
	uint8_t flag;
	void* data;
	const tFont** font;
	tImage* icon;
	char* text;
} stateData_t;

typedef const struct{
	void *Next;
	void *Previous;
	void *Parent;
	void *Child;
	FuncPtr HandUp;
	FuncPtr HandDown;
	FuncPtr HandLeft;
	FuncPtr HandRight;
	/* FuncPtr HandOk; */
	FuncPtr HandLcd;
	stateData_t* data;
	char Text[];
}stateElement ;

//externs
extern stateElement NullState;
extern stateElement* CurrState;
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
extern stateData_t insideTempItemData;
extern stateData_t outsideTempItemData;
extern stateData_t coolantTempItemData;

//defines and macros
#define NULL_ENTRY NullState
#define NULL_FUNC (void*)0
#define NULL_TEXT 0x00
#define NULL_DATA	(stateData_t*)0

#define NEXT         CurrState->Next
#define PREVIOUS 	 CurrState->Previous
#define PARENT 		 CurrState->Parent
#define CHILD 		 CurrState->Child

#define MAKE_STATE(Name,Next,Previous,Parent,Child,HandUp,HandDown,HandLeft,HandRight,HandLcd,Data,Text)\
	extern stateElement Next;\
	extern stateElement Previous;\
	extern stateElement Parent;\
	extern stateElement Child;\
	stateElement Name={(void*)&Next,(void*)&Previous,(void*)&Parent,(void*)&Child,(FuncPtr)HandUp,(FuncPtr)HandDown,(FuncPtr)HandLeft,(FuncPtr)HandRight,(FuncPtr)HandLcd,Data,{Text}}

//prototypes
void ChangeState	(stateElement* NewState);
void ChangeNext		(void);
void ChangePrev		(void);
void ChangeParent	(void);
void ChangeChild	(void);

#endif /* MENU_H_ */
