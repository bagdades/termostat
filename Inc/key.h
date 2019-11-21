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

/*------------------KEY---------------------------------------*/
/* #define KEY_UP    		0 */
/* #define KEY_DOWN  		1 */
/* #define KEY_LEFT	 	5 */
/* #define KEY_RIGHT	 	6 */
/* #define KEY_OK	 		7 */

#define DELAY_SHORT 2
#define DELAY_LONG  30

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

#endif /* KEY_H_ */
