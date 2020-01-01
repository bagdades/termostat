#ifndef  INIT_INC
#define  INIT_INC

#include "menu.h"
#include "lcdwg.h"
#include "arial7.h"
#include "arial9_b.h"
#include "font.h"
#include "m_rtc_2001.h"
#include "i2c.h"
#include "ds18b20.h"
#include "onewire.h"

#define AUTO_MODE_WORK		0
#define MANUAL_MODE_WORK	1
#define OFF_MODE_WORK		2

#define I2C_ADDR_1WIRE_SENSOR_CODE	0x32
#define I2C_ADDR_SAVE_EEPROM		0x0

typedef struct _sensorID_t {
	uint8_t idx;
	uint8_t romcode[OW_ROMCODE_SIZE];
} sensorID_t;


/* Function prototypes */
void InitMain(void);
void Termostat(void);
int16_t TermGetWorkTemp(void);
void WriteEepromValue(void);

#endif   /* ----- #ifndef INIT_INC  ----- */
