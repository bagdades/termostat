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

#define I2C_ADDR_SAVE_EEPROM			0x0
#define I2C_ADDR_1WIRE_SENSOR_CODE		0x20
#define I2C_ADDR_INSIDE_SENSOR_CODE		0x20
#define I2C_ADDR_OUTSIDE_SENSOR_CODE	0x28
#define I2C_ADDR_COOLANT_SENSOR_CODE	0x30

/* Function prototypes */
void InitMain(void);
void Termostat(void);
int16_t TermGetWorkTemp(void);
void WriteEepromValue(void);
void WriteEepromSensor(uint8_t addr);

#endif   /* ----- #ifndef INIT_INC  ----- */
