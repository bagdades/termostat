#ifndef  SCHEDULER_INC
#define  SCHEDULER_INC

#include <stdint.h>
/* #include <avr/io.h> */
/* #include <avr/interrupt.h> */
/* #include "usart.h" */
/* #include "parser.h" */

#define MAXTASKS	8

//TIMER
#define T0_PRESC	1024UL
#define T0_FREQ		1000UL
#define FALSE		0
#define TRUE		1
/* #define T0_INIT		255 - (F_CPU/(T0_FREQ * T0_PRESC)) */

typedef struct _task {
	void (*pfunc)(void);
	uint16_t delay;
	uint16_t period;
	uint8_t run;
}task;

//Protorypes
void OS_Init(void);
uint8_t OS_AddTask(void (*taskFunc)(void), uint16_t taskDelay, uint16_t taskPeriod);
void OS_Dispatch(void);
void OS_DeleteTask(void (*taskFunc)(void));
void OS_Update(void);
#endif   /* ----- #ifndef SCHEDULER_INC  ----- */
