/*
 * lcdwg.h
 *
 *  Created on: 10 груд. 2012
 *      Author: vovan
 */

#ifndef LCDWG_H_
#define LCDWG_H_

#include <inttypes.h>
#include "gpio.h"
#include "font.h"
#include "scheduler.h"
#include "menu.h"
#include "arial9_b.h"
#include "arial7.h"
#include "seg25.h"
#include "Arial25b.h"
#include "dig.h"
/* #include "arial34b.h" */

/* General constants for driver */
#ifndef FALSE
#define FALSE                      0
#endif
#ifndef TRUE
#define TRUE                       1
#endif

/* For return value */
#define OK                         0
#define OUT_OF_BORDER              1
#define OK_WITH_WRAP               2


#define LCD_X_RES				   128
#define LCD_Y_RES				   64
#define LCD_Y_RES_REAL			   65	 /* Y resolution real */

#define LCD_X_MAX				   (LCD_X_RES/6)
#define LCD_Y_MAX				   6

#define EMPTY_SPACE_BARS           2
#define BAR_X                      5
#define BAR_Y                      38
#define LCD_CACHE_SIZE       ((LCD_X_RES * LCD_Y_RES)/8)

/*** Flags for place text **/
#define	DT_DEFAULT	0x00
#define	DT_LEFT		0x00
#define	DT_RIGHT	0x01
#define	DT_CENTER	0x02
#define	DT_VDEFAULT	0x00
#define	DT_TOP		0x00
#define	DT_BOTTOM	0x04
#define	DT_VCENTER	0x08

/* #define LCD_CS1_PIN					8 */
/* #define LCD_CS2_PIN 				9 */
/* #define LCD_RST_PIN					10 */
/* #define LCD_DI_PIN					11 */
/* #define LCD_CLK_PIN					12 */
/* #define LCD_E_PIN					13 */
/* #define LCD_DATA_PIN				14 */
/* #define LCD_CE_PIN					15 */

#define LENGTH_MENU_STRING		LCD_X_RES - 7

#define LCD_DELAY { int i=16; while(i) {__NOP(); i--;}; }

#define DIAGNOSTIC_DATA_LENGTH		6
#define COMMA						0x80
#define NO_COMMA					0
#define MENU_ITEM_TEXT				0x40

typedef enum
{
    LCD_CMD  = 0,//!< LCD_CMD
    LCD_DATA = 1 //!< LCD_DATA

} lcdDI_t;

typedef enum
{
	LCD_MODE_NORM = 0,
	LCD_MODE_INVERSE
}lcdMode_t;

typedef enum{
	LCD_CS1 = 0,
	LCD_CS2,
	LCD_CS_BOTH
}lcdCS_t;

typedef enum {
	MENU_MODE_LIST = 0,
	MENU_MODE_SELECT
}menuMode_t;

typedef struct{
	uint8_t x;
	uint8_t y;
	uint8_t length;
	uint8_t height;
}rect_t;

#define RECT_SET(rect,_x,_y,l,h) { (rect).x = (_x); (rect).y = (_y); (rect).length = (l); (rect).height = (h); }


/*
bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number × 4)
BB_ADR = SRAM_BB_BASE + ( (ADR - SRAM_BASE) *32) + (BIT * 4)
*/
#define varClrBitBB(var, BitNumber)(*(uint32_t *)\
				(SRAM_BB_BASE + ((((uint32_t)&var) - SRAM_BASE) << 5) + ((BitNumber) << 2)) = 0)
#define varSetBitBB(var, BitNumber)(*(uint32_t *)\
				(SRAM_BB_BASE + ((((uint32_t)&var) - SRAM_BASE) << 5) + ((BitNumber) << 2)) = 1)

/* Functions Prototypes */

void LcdInit			(void);
void LcdSend			(uint8_t data, lcdDI_t cd, lcdCS_t cs);
void LcdClear			(void);
void LcdUpdate			(void);
uint8_t LcdDrawChar		(uint8_t x,uint8_t y,tFont font,lcdMode_t mode,uint8_t ch);
void LcdDrawString		(uint8_t x,uint8_t y,tFont font,lcdMode_t mode,const char* string);
uint8_t LcdDrawText		(rect_t rect,uint8_t lcdFlags,tFont font,lcdMode_t mode,const char* str);
uint8_t LcdGetStrWidth	(tFont font,const char* str);
uint8_t LcdDrawPixel	(uint8_t x,uint8_t y,lcdMode_t mode);
uint8_t LcdDrawLine 	(uint8_t x1 ,uint8_t x2,uint8_t y1 ,uint8_t y2,lcdMode_t mode);
uint8_t LcdDrawRect		(rect_t rect,lcdMode_t mode);
uint8_t LcdDrawFrame	(uint8_t x1 , uint8_t x2 , uint8_t y1 , uint8_t y2 , lcdMode_t mode);
void LcdDrawImage		(uint8_t x, uint8_t y, uint8_t mode,tImage image);
void LcdShow(void);
void LcdMenuList(void);
void LcdMenuSelect(void);
void LcdDrawOneItem(void);
void LcdSetClock(void);

#endif /* LCDWG_H_ */
