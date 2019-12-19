/*
 * key.h
 *
 *  Created on: 25 вер. 2012
 *      Author: vovan
 */

#ifndef KEY_H_
#define KEY_H_

#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "inttypes.h"
#include "menu.h"
#include "m_rtc_2001.h"
#include "init.h"

/*------------------KEY---------------------------------------*/
/* #define KEY_UP    		0 */
/* #define KEY_DOWN  		1 */
/* #define KEY_LEFT	 	5 */
/* #define KEY_RIGHT	 	6 */
/* #define KEY_OK	 		7 */

#define DELAY_SHORT 2
#define DELAY_LONG  30
#define LEAP 		1
#define NOT_LEAP 	0

enum keyPress{
		_UP=1,
		_DOWN,
		_LEFT,
		_RIGHT,
		_OK
};

/*	Prototypes	*/
/* void KeyInit(void); */
void KeyScan(void);
void KeyHand(void);
void KeySetUpTimeDate(void);
void KeySetDownTimeDate(void);
uint8_t CheckLeap(uint8_t);
void KeySetModeWork(void);
void KeySetUpVar(void);
void KeySetDownVar(void);
void KeySetUpBoundTime(void);
void KeySetDownBoundTime(void);
void KeyToogleState(void);
#endif /* KEY_H_ */
