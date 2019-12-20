#ifndef  INIT_INC
#define  INIT_INC

#include "menu.h"
#include "lcdwg.h"
#include "arial7.h"
#include "arial9_b.h"
#include "font.h"
#include "m_rtc_2001.h"
#include "i2c.h"

#define AUTO_MODE_WORK		0
#define MANUAL_MODE_WORK	1
#define OFF_MODE_WORK		2

/* Function prototypes */
void InitMain(void);
void Termostat(void);
int16_t TermGetWorkTemp(void);
void WriteEepromValue(void);

#endif   /* ----- #ifndef INIT_INC  ----- */
