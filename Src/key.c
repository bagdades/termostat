/*
 * key.c
 *
 *  Created on: 25 вер. 2012
 *      Author: vovan
 */

#include "key.h"
/* #include "menu.h" */

extern stateElement startState;
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
			/* pFunc = (FuncPtr)(&CurrState->HandUp); */
			pFunc = CurrState->HandUp;
			if (pFunc == (void*) 0)
				break;
			pFunc();
			break;
		case _DOWN:
			keyPressed = 0;
			/* pFunc = (FuncPtr)(&CurrState->HandDown); */
			pFunc = CurrState->HandDown;
			if (pFunc == (void*) 0)
				break;
			pFunc();
			break;
		case _LEFT:
			keyPressed = 0;
			/* HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin); */
			/* pFunc = (FuncPtr)(&CurrState->HandLeft); */
			pFunc = CurrState->HandLeft;
			if (pFunc == (void*) 0)
				break;
			pFunc();
			break;
		case _RIGHT:
			keyPressed = 0;
			/* HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin); */
			/* pFunc = (FuncPtr)(&CurrState->HandRight); */
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
	/* uint32_t counterValue; */
	/* uint8_t idx = CurrState->Text[0] - '0'; */
	/* uint8_t value = CurrState->Text[1] - '0'; */
	/* if (CurrState == (stateElement*) &setDay) { */
	/* 	if (timeBufferInt[MONTH] == 4 || timeBufferInt[MONTH] == 6 */
	/* 			|| timeBufferInt[MONTH] == 9 || timeBufferInt[MONTH] == 11) */
	/* 		value = 30; */
	/* 	else if (timeBufferInt[MONTH] == 2) { */
	/* 		if (CheckLeap(timeBufferInt[YEAR])) */
	/* 			value = 29; */
	/* 		else */
	/* 			value = 28; */
	/* 	} else */
	/* 		value = 31; */
	/* } */
	/* if (timeBufferInt[idx] < value) */
	/* 	timeBufferInt[idx]++; */
	/* else if (timeBufferInt[idx] >= value) { */
	/* 	timeBufferInt[idx] = 0; */
	/* 	if (CurrState == (stateElement*) &setDay */
	/* 			|| CurrState == (stateElement*) &setMonth) */
	/* 		timeBufferInt[idx] = 1; */
	/* } */
	/* counterValue = (timeBufferInt[HOUR] * 3600) + (timeBufferInt[MIN] * 60) */
	/* 		+ timeBufferInt[SEC]; */
	/* RTC_SetCounter(counterValue); */
}
void KeySetDownTimeDate(void) {
	/* uint32_t counterValue; */
	/* uint8_t idx = CurrState->Text[0] - '0'; */
	/* uint8_t value = CurrState->Text[1] - '0'; */
	/* if (CurrState == (stateElement*) &setDay) { */
	/* 	if (timeBufferInt[MONTH] == 4 || timeBufferInt[MONTH] == 6 */
	/* 			|| timeBufferInt[MONTH] == 9 || timeBufferInt[MONTH] == 11) */
	/* 		value = 30; */
	/* 	else if (timeBufferInt[MONTH] == 2) { */
	/* 		if (CheckLeap(timeBufferInt[YEAR])) */
	/* 			value = 29; */
	/* 		else */
	/* 			value = 28; */
	/* 	} else */
	/* 		value = 31; */
	/* } */
	/* timeBufferInt[idx]--; */
	/* if (timeBufferInt[idx] < 1 */
	/* 		&& (CurrState == (stateElement*) &setDay */
	/* 				|| CurrState == (stateElement*) &setMonth)) */
	/* 	timeBufferInt[idx] = value; */
	/* if (timeBufferInt[idx] < 0) */
	/* 	timeBufferInt[idx] = value; */
	/* if (CurrState == (stateElement*) &setSec) */
	/* 	timeBufferInt[idx] = 0; */
	/* counterValue = (timeBufferInt[HOUR] * 3600) + (timeBufferInt[MIN] * 60) */
	/* 		+ timeBufferInt[SEC]; */
	/* RTC_SetCounter(counterValue); */
}
