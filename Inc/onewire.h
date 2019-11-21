#ifndef _1wire_h_
#define _1wire_h_

#include <inttypes.h>
#include "stm32f1xx_hal.h"
#include "delay.h"

/*******************************************/
/* Hardware connection                     */
/*******************************************/

/* Define OW_ONE_BUS if only one 1-Wire-Bus is used
   in the application -> shorter code.
   If not defined make sure to call ow_set_bus() before using 
   a bus. Runtime bus-select increases code size by around 300 
   bytes so use OW_ONE_BUS if possible */

/*******************************************/

// #define OW_SHORT_CIRCUIT  0x01

#define OW_MATCH_ROM	0x55
#define OW_SKIP_ROM	    0xCC
#define	OW_SEARCH_ROM	0xF0

#define	OW_SEARCH_FIRST	0xFF		// start new search
#define	OW_PRESENCE_ERR	0xFF
#define	OW_DATA_ERR	    0xFE
#define OW_LAST_DEVICE	0x00		// last device found
//			0x01 ... 0x40: continue searching

// rom-code size including CRC
#define OW_ROMCODE_SIZE 8

#define OW_DELAY(x)		_delay_us(x)

/* Function prototypes */
void OW_Init(void);
uint8_t OW_Reset(void);
uint8_t OW_BitIO( uint8_t b );
uint8_t OW_ByteWR( uint8_t b );
uint8_t OW_ByteRD( void );
uint8_t OW_RomSearch( uint8_t diff, uint8_t *id );
void OW_Command( uint8_t command, uint8_t *id );
void OW_ParasiteEnable(void);
void OW_ParasiteDisable(void);
uint8_t OW_InputPinState(void);

#endif

