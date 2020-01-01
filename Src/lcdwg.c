/*
 * lcdwg.c
 *
 *  Created on: 10 ????. 2012
 *      Author: vovan
 */

#include <string.h>
#include "stm32f1xx_hal.h"
#include "lcdwg.h"
#include "delay.h"
/* #include "src/stm32f10x.h" */

///* Variable to decide whether update Lcd Cache is active/nonactive */
static uint8_t lcdCache[LCD_CACHE_SIZE];
static uint16_t lcdCacheIdx;
static uint16_t loWaterMark;
static uint16_t hiWaterMark;
static uint8_t updateLcd;

const tFont* fontMenu;
const tFont* fontDigital;
uint8_t shiftRow;
uint8_t lcdMode;
char diagnosticChar[VARIABLE_CHAR_DATA_LENGTH];


extern uint8_t ticksBlink;

void LcdInit(void) {

	/* Reset LCD */
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);

	LcdSend(0x3F, LCD_CMD, LCD_CS_BOTH); //Display ON
	LcdSend(0x40, LCD_CMD, LCD_CS_BOTH); //Y address 0
	LcdSend(0xB8, LCD_CMD, LCD_CS_BOTH); //X address 0
	LcdSend(0xC0, LCD_CMD, LCD_CS_BOTH); //Display start line 0
	LcdClear();
	LcdUpdate();
}

/**
 * @name LcdSend
 * @param data-> byte of data or commant 
 * @param cd-> LCD_DATA or LCD_CMD. See enum in lcdwg.h
 * @param cs-> LCD_CS1 or LCD_CS2 or LCD_CS_BOTH . See enum in lcdwg.he
 */
void LcdSend(uint8_t data, lcdDI_t cd, lcdCS_t cs) {
	int bitcnt;
	if (cd == LCD_DATA)
		HAL_GPIO_WritePin(LCD_DI_GPIO_Port, LCD_DI_Pin, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(LCD_DI_GPIO_Port, LCD_DI_Pin, GPIO_PIN_RESET);

	if (cs == LCD_CS1)
		HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, GPIO_PIN_SET);
	else if (cs == LCD_CS2)
		HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, GPIO_PIN_SET);
	else {
		HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, GPIO_PIN_SET);
	}

	for (bitcnt = 8; bitcnt > 0; bitcnt--) {
		// Set Clock Idle level LOW.
		HAL_GPIO_WritePin(LCD_SHIFT_GPIO_Port, LCD_SHIFT_Pin, GPIO_PIN_RESET);
		if ((data & 0x80) == 0x80) {
			// clocks in the MSb first.
			HAL_GPIO_WritePin(LCD_DATA_GPIO_Port, LCD_DATA_Pin, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(LCD_DATA_GPIO_Port, LCD_DATA_Pin, GPIO_PIN_RESET);
		}
		// Data is clocked on the rising edge of SCK.
		HAL_GPIO_WritePin(LCD_SHIFT_GPIO_Port, LCD_SHIFT_Pin, GPIO_PIN_SET);
		data = data << 1; // Logical shift data by 1 bit left.
	}
	/* Strob */
	HAL_GPIO_WritePin(LCD_CLK_GPIO_Port, LCD_CLK_Pin, GPIO_PIN_SET);
	asm("nop");
	HAL_GPIO_WritePin(LCD_CLK_GPIO_Port, LCD_CLK_Pin, GPIO_PIN_RESET);
	asm("nop");
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	/* uint8_t a; */
	/* for (a = 0; a < 72; a++) { */
	/* 	asm("nop"); */
	/* } */
	_delay_us(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
	asm("nop");

	HAL_GPIO_WritePin(LCD_CS1_GPIO_Port, LCD_CS1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CS2_GPIO_Port, LCD_CS2_Pin, GPIO_PIN_RESET);
}

/**
 * @name LcdClear
 * @note Clear ram buffer for lcd
 */
void LcdClear(void) {
	memset(lcdCache, 0, LCD_CACHE_SIZE);
	loWaterMark = 0;
	hiWaterMark = LCD_CACHE_SIZE - 1;

	/* Set update flag to be true */
	updateLcd = TRUE;
}

/**
 * @name LcdUpdate
 * @note Copy ram buffer to lcd
 */
void LcdUpdate(void) {
	uint16_t i = 0;
	uint8_t row, column;
	uint8_t rowEnd;
	lcdCS_t cs = LCD_CS1;

	if (loWaterMark < 0)
		loWaterMark = 0;
	else if (loWaterMark >= LCD_CACHE_SIZE)
		loWaterMark = LCD_CACHE_SIZE - 1;

	if (hiWaterMark < 0)
		hiWaterMark = 0;
	else if (hiWaterMark >= LCD_CACHE_SIZE)
		hiWaterMark = LCD_CACHE_SIZE - 1;

	row = loWaterMark / LCD_X_RES;
	rowEnd = hiWaterMark / LCD_X_RES;
	i = loWaterMark;
	for (; row <= rowEnd; row++) {
		LcdSend(0xB8 + row, LCD_CMD, LCD_CS_BOTH);
		LcdSend(0x40, LCD_CMD, LCD_CS_BOTH);
		for (column = 0; column < 64; column++) {
			LcdSend(lcdCache[i++], LCD_DATA, cs);
		}
		cs = LCD_CS2;
		for (column = 0; column < 64; column++) {
			LcdSend(lcdCache[i++], LCD_DATA, cs);
		}
		cs = LCD_CS1;
	}

	/*  Reset watermark pointers. */
	loWaterMark = LCD_CACHE_SIZE - 1;
	hiWaterMark = 0;

	/* Set update flag to be true */
	updateLcd = FALSE;
}
/**
 * @name LcdDrawChar
 * 
 * 
 * @param x ->absolute coordinate x in pixel
 * @param y ->absolute coordinate y in pixel
 * @param font-> font of the char
 * @param mode > LCD_MODE_INVERSE or LCD_MODE_NORM. See enum in lcdwg.h.
 * @param ch -> char
 * @return width of the char
 */
uint8_t LcdDrawChar(uint8_t x, uint8_t y, tFont font, lcdMode_t mode,
		uint8_t ch) {
	uint8_t i, j, n, m;
	uint8_t block;
	uint8_t chr;
	if ((ch < 0x20) || (ch > 0xFF)) {
		/* Convert to a printable character. */
		ch = '#';
	}
	if (ch == 'Є')
		chr = 0x9F;
	else if (ch == 'І')
		chr = 0xA0;
	else if (ch == 'Ї')
		chr = 0xA1;
	else if (ch == 'є')
		chr = 0xA2;
	else if (ch == 'і')
		chr = 0xA3;
	else if (ch == 'ї')
		chr = 0xA4;
	else if (ch > '~')
		chr = ch - 0x61;
	else
		chr = ch - font.chars[0].code;
	uint8_t width = font.chars[chr].image->width;
	uint8_t height = font.chars[chr].image->height;
	lcdCacheIdx = x + ((y / 8) * LCD_X_RES);
	if (lcdCacheIdx < loWaterMark) {
		/* Update low marker. */
		loWaterMark = lcdCacheIdx;
	}
	n = m = 0;
	// Read first byte block of the image char
	block = font.chars[chr].image->data[m++];
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (mode == LCD_MODE_INVERSE) {
				if (block & 0x80)
					varClrBitBB(lcdCache[lcdCacheIdx], y % 8);
				else
					varSetBitBB(lcdCache[lcdCacheIdx], y % 8);
			} else {
				if (block & 0x80)
					varSetBitBB(lcdCache[lcdCacheIdx], y % 8);
				else
					varClrBitBB(lcdCache[lcdCacheIdx], y % 8);
			}
			block = block << 1;
			// Count shift of the block
			n++;
			if (n == 8) {
				n = 0;
				// if shifted all block , read next block
				block = font.chars[chr].image->data[m++];
			}
			lcdCacheIdx++; // next position x in pixel
		}
		y++;
		if (y >= LCD_Y_RES)
			break;
		lcdCacheIdx = x + ((y / 8) * LCD_X_RES);
	}
	if (lcdCacheIdx > hiWaterMark) {
		/* Update high marker. */
		hiWaterMark = lcdCacheIdx;
	}
	updateLcd = TRUE;
	return width;
}
/**
 * @name LcdDrawString
 * @param x-> absolute coordinate x in pixel
 * @param y-> absolute coordinate y in pixel
 * @param font-> font of char
 * @param mode ->LCD_MODE_INVERSE or LCD_MODE_NORM. See enum in lcdwg.h.
 * @param string -> pointer on the input string 
 */
void LcdDrawString(uint8_t x, uint8_t y, tFont font, lcdMode_t mode,
		const char* string) {
	uint8_t i, j;
	uint8_t width = 0;
	uint8_t height = font.chars[0].image->height;
	j = y;
	while (*string) {
		if (width) {
			/* Draw interval between char (width 1 pixel)*/
			lcdCacheIdx = x + ((y / 8) * LCD_X_RES);
			j = y;
			for (i = 0; i < height; i++) {
				if (mode == LCD_MODE_INVERSE)
					varSetBitBB(lcdCache[lcdCacheIdx], j % 8);
				else
					varClrBitBB(lcdCache[lcdCacheIdx], j % 8);
				j++;
				if (j % 8 == 0) {
					j++;
					lcdCacheIdx = x + ((j / 8) * LCD_X_RES);
				}
			}
			x++;
			if (x >= LCD_X_RES)
				break;
			lcdCacheIdx = x + ((y / 8) * LCD_X_RES);
		}
		width = LcdDrawChar(x, y, font, mode, *string);
		string++;
		x += width;
		if (x >= LCD_X_RES)
			break;
	}
	updateLcd = TRUE;
}
/**
 * @name LcdDrawText
 * @param rect->rectangle for text
 * @param lcdFlags-> Flags for place text. See enum in lcdwg.h
 * @param font-> font of the text
 * @param mode->LCD_MODE_INVERSE or LCD_MODE_NORM. See enum in lcdwg.h.
 * @param str-> pointer on the string of text
 * @return
 */
uint8_t LcdDrawText(rect_t rect, uint8_t lcdFlags, tFont font, lcdMode_t mode,
		const char* str) {
	uint8_t w;
	uint8_t h;
	uint8_t _x, _y, i, j, bit;
	if ((rect.x + rect.length) >= LCD_X_RES)
		return OUT_OF_BORDER;
	if ((rect.y + rect.height) >= LCD_Y_RES)
		return OUT_OF_BORDER;
	w = LcdGetStrWidth(font, str);
	h = font.chars[0].image->height;

	if (lcdFlags & DT_CENTER) { // Alignment center
		_x = rect.x + (rect.length - w) / 2;
	} else if (lcdFlags & DT_RIGHT) { // Aligment right
		_x = rect.x + rect.length - w;
	} else { // Alignment left (by default)
		_x = rect.x;
	}
	if (lcdFlags & DT_VCENTER) { // Alignment center by vertical
		_y = rect.y + (rect.height - h) / 2;
	} else if (lcdFlags & DT_BOTTOM) { // Alignment bottom
		_y = rect.y + rect.height - h;
	} else { // Alignment up (by default)
		_y = rect.y;
	}
	lcdCacheIdx = rect.x + ((rect.y / 8) * LCD_X_RES);
	if (lcdCacheIdx < loWaterMark) {
		/* Update low marker. */
		loWaterMark = lcdCacheIdx;
	}
	bit = rect.y;
	for (i = 0; i < rect.height; i++) {
		for (j = 0; j < rect.length; j++) {
			if (mode == LCD_MODE_INVERSE)
				varSetBitBB(lcdCache[lcdCacheIdx], bit % 8);
			else
				varClrBitBB(lcdCache[lcdCacheIdx], bit % 8);
			lcdCacheIdx++;
		}
		bit++;
		lcdCacheIdx = rect.x + ((bit / 8) * LCD_X_RES);
	}
	if (lcdCacheIdx > hiWaterMark) {
		/* Update high marker. */
		hiWaterMark = lcdCacheIdx;
	}
	LcdDrawString(_x, _y, font, mode, str);

	/* Set update flag to be true */
	updateLcd = TRUE;
	return OK;
}
/*
 * Name         :	LcdGetStrWidth
 * Description  :
 * Argument(s)  :	font -> font of the string
 * Return value :	string width
 * Note         :
 */
uint8_t LcdGetStrWidth(tFont font, const char* str) {
	uint8_t width = 0;
	uint8_t length = 0;
	uint8_t chr;
	while (*str) {
		if (*str == 'Є')
			chr = 0x9F;
		else if (*str == 'І')
			chr = 0xA0;
		else if (*str == 'Ї')
			chr = 0xA1;
		else if (*str == 'є')
			chr = 0xA2;
		else if (*str == 'і')
			chr = 0xA3;
		else if (*str == 'ї')
			chr = 0xA4;
		else if (*str > '~')
			chr = *str - 0x61;
		else
			chr = *str - font.chars[0].code;
		if (width)
			length++;
		width = font.chars[chr].image->width;
		length += width;
		str++;
	}
	return length;
}
/*
 * Name         :  LcdDrawPixel
 * Description  :  Displays a pixel at given absolute (x, y) location.
 * Argument(s)  :  x, y -> Absolute pixel coordinates
 *                 mode -> LCD_MODE_INVERSE or LCD_MODE_NORM. See enum in lcdwg.h.
 * Return value :  see return value on lcdwg.h
 */
uint8_t LcdDrawPixel(uint8_t x, uint8_t y, lcdMode_t mode) {

	/* Prevent from getting out of border */
	if (x > LCD_X_RES)
		return OUT_OF_BORDER;
	if (y > LCD_Y_RES)
		return OUT_OF_BORDER;

	lcdCacheIdx = x + ((y / 8) * LCD_X_RES);

	if (lcdCacheIdx < loWaterMark) {
		/* Update low marker. */
		loWaterMark = lcdCacheIdx;
	}

	if (mode == LCD_MODE_INVERSE)
		varClrBitBB(lcdCache[lcdCacheIdx], y % 8);
	else
		varSetBitBB(lcdCache[lcdCacheIdx], y % 8);

	if (lcdCacheIdx > hiWaterMark) {
		/* Update high marker. */
		hiWaterMark = lcdCacheIdx;
	}

	return OK;
}
/*
 * Name         :  LcdLine
 * Description  :  Draws a line between two points on the display.
 * Argument(s)  :  x1, y1 -> Absolute pixel coordinates for line origin.
 *                 x2, y2 -> Absolute pixel coordinates for line end.
 *                 mode -> LCD_MODE_INVERSE or LCD_MODE_NORM. See enum in lcdwg.h.
 * Return value :  see return value on lcdwg.h
 */
uint8_t LcdDrawLine(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2,
		lcdMode_t mode) {
	uint8_t i;

	if (y1 == y2) {
		if (x1 < x2) {
			for (i = x1; i <= x2; i++)
				LcdDrawPixel(i, y1, mode);
		} else {
			for (i = x2; i <= x1; i++)
				LcdDrawPixel(i, y1, mode);
		}
	} else if (x1 == x2) {
		if (y1 < y2) {
			for (i = y1; i <= y2; i++)
				LcdDrawPixel(x1, i, mode);
		} else {
			for (i = y2; i <= y1; i++)
				LcdDrawPixel(x1, i, mode);
		}
	} else
		return OUT_OF_BORDER;
	/* Set update flag to be true */
	updateLcd = TRUE;
	return OK;
}
/*
 * Name         :  LcdDrawRect
 * Description  :  Display a rectangle.
 * Argument(s)  :  x1   -> absolute first x axis coordinate
 *                 y1   -> absolute first y axis coordinate
 *				   x2   -> absolute second x axis coordinate
 *				   y2   -> absolute second y axis coordinate
 *				   mode -> LCD_MODE_INVERSE or LCD_MODE_NORM. See enum in lcdwg.h.
 * Return value :  see return value on lcdwg.h.
 */
uint8_t LcdDrawRect(rect_t rect, lcdMode_t mode) {
	uint8_t i, j;

	/* Checking border */
	if ((rect.x > LCD_X_RES) || ((rect.x + rect.length) > LCD_X_RES)
			|| (rect.y > LCD_Y_RES) || ((rect.y + rect.height) > LCD_Y_RES))
		/* If out of border then return */
		return OUT_OF_BORDER;

	lcdCacheIdx = rect.x + ((rect.y / 8) * LCD_X_RES);
	if (lcdCacheIdx < loWaterMark) {
		/* Update low marker. */
		loWaterMark = lcdCacheIdx;
	}

	uint8_t bit = rect.y;
	for (i = 0; i < rect.height; i++) {
		for (j = 0; j < rect.length; j++) {
			if (mode == LCD_MODE_INVERSE)
				varClrBitBB(lcdCache[lcdCacheIdx], bit % 8);
			else
				varSetBitBB(lcdCache[lcdCacheIdx], bit % 8);
			lcdCacheIdx++;
		}
		bit++;
		lcdCacheIdx = rect.x + ((bit / 8) * LCD_X_RES);
	}
	if (lcdCacheIdx > hiWaterMark) {
		/* Update high marker. */
		hiWaterMark = lcdCacheIdx;
	}
	updateLcd = TRUE;
	return OK;
}
/**
 * @name LcdDrawFrame
 * @param x1 -> absolute first x axis coordinate 
 * @param x2 -> absolute second x axis coordinate
 * @param y1 -> absolute first y axis coordinate
 * @param y2 -> absolute second y axis coordinate
 * @param mode -> LCD_MODE_INVERSE or LCD_MODE_NORM. See enum in lcdwg.h.
 * @return	see return value on lcdwg.h.
 */
uint8_t LcdDrawFrame(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2,
		lcdMode_t mode) {
	uint8_t i;
	if (x1 > (LCD_X_RES - 1) || x2 > (LCD_X_RES - 1))
		return OUT_OF_BORDER;
	if (y1 > (LCD_Y_RES_REAL - 2) || y2 > (LCD_Y_RES_REAL - 2))
		return OUT_OF_BORDER;
	for (i = x1; i <= x2; i++)
		LcdDrawPixel(i, y1, mode);
	for (i = y1; i <= y2; i++)
		LcdDrawPixel(x2, i, mode);
	for (i = y1; i <= y2; i++)
		LcdDrawPixel(x1, i, mode);
	for (i = x1; i <= x2; i++)
		LcdDrawPixel(i, y2, mode);
	if (lcdCacheIdx > hiWaterMark) {
		/* Update high marker. */
		hiWaterMark = lcdCacheIdx;
	}
	updateLcd = TRUE;
	return OK;
}

/**
 * @name LcdDrawImage
 * @param x-> absolute coordinate x in pixel
 * @param y-> absolute coordinate y in pixel
 * @param mode-> LCD_MODE_INVERSE or LCD_MODE_NORM. See enum in lcdwg.h.
 * @param image-> pointer to image
 */
void LcdDrawImage(uint8_t x, uint8_t y, uint8_t mode, tImage image) {
	uint8_t i, j, n, m, bit;
	uint8_t block;
	uint8_t width = image.width;
	uint8_t height = image.height;
	lcdCacheIdx = x + ((y / 8) * LCD_X_RES);
	if (lcdCacheIdx < loWaterMark) {
		/* Update low marker. */
		loWaterMark = lcdCacheIdx;
	}
	bit = y;
	n = m = 0;
	block = image.data[m++];
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (mode == LCD_MODE_INVERSE) {
				if (block & 0x80)
					varClrBitBB(lcdCache[lcdCacheIdx], bit % 8);
				else
					varSetBitBB(lcdCache[lcdCacheIdx], bit % 8);
			} else {
				if (block & 0x80)
					varSetBitBB(lcdCache[lcdCacheIdx], bit % 8);
				else
					varClrBitBB(lcdCache[lcdCacheIdx], bit % 8);
			}
			block = block << 1;
			n++;
			if (n == 8) {
				n = 0;
				block = image.data[m++];
			}
			lcdCacheIdx++;
		}
		bit++;
		lcdCacheIdx = x + ((bit / 8) * LCD_X_RES);
	}
	if (lcdCacheIdx > hiWaterMark) {
		/* Update high marker. */
		hiWaterMark = lcdCacheIdx;
	}
}

void LcdShow(void)
{
	FuncPtr pFunc;
	pFunc = CurrState->HandLcd;
	pFunc();
	OS_AddTask(LcdShow, 0, 100);
	if (updateLcd == TRUE) 
		LcdUpdate();
}

void LcdDrawMenu(menuMode_t mode) {
	uint8_t numberRow;
	uint8_t rowHeight;  //in pixel
	uint8_t currItem = 1;
	uint8_t numberItem = 0;
	uint8_t slideStart;
	uint8_t slideHeight;
	uint8_t i, n = 0;
	stateElement* rowElement;
	stateElement* parElement;
	rect_t rec;
	rowHeight = fontMenu->chars[0].image->height + 3;  //запас по два рядку зверху і знизу (міжрядковий проміжок)
	numberRow = LCD_Y_RES / rowHeight;
	/* Якщо існує пункт меню parent , залишаємо місце для заголовка */
	if (CurrState->Parent != (void*) &NULL_ENTRY)
		numberRow -= 1;
	if ((void*) CurrState == (void*) &NULL_ENTRY)
		return;
	rowElement = CurrState;
	parElement = CurrState;
	/*Визначаємо перший елемент меню відносно поточного*/
	while (rowElement->Previous != (void*) &NULL_ENTRY) {
		currItem++;
		rowElement = rowElement->Previous;
	}
	/* Визначаємо кількість пунктів меню */
	while (parElement->Next != (void*) &NULL_ENTRY) {
		numberItem++;
		parElement = parElement->Next;
	}
	numberItem += currItem;
	/* Якщо поточний пункт меню виходить за рамки екрана 
	 * зміщуємо перший видмий пункт доки поточний не попаде 
	 * в поле зображення і зберігаємо кількість зсувів
	 */
	/*
	 *  TODO При переході в меню child or parent, shiftRow онуляти в
	 * 		в зовнішній функції переходу меню
	 */

	if (currItem > numberRow) {
		for (i = 0; i < (currItem - numberRow); i++) {
			rowElement = rowElement->Next;
			n++;
		}
		if (shiftRow > n) {  //якщо зсунення раніше було нижче поточного пункту
			if ((shiftRow - n) >= numberRow) {  // і пункт попадає в зону екрану
				while ((shiftRow - n) >= numberRow)
					shiftRow--;
			}
			n = shiftRow - n;
			for (i = 0; i < n; i++) {
				rowElement = rowElement->Next;  // залишаємо попередній зсув
			}
		} else
			shiftRow = n;
		n = 0;
	}
	if (currItem <= numberRow) {  //якщо пункт меню не попадає в зону екрану 
		while (!(currItem - shiftRow))
			shiftRow--;  //зменшуємо зсув
		for (i = 0; i < shiftRow; i++)
			rowElement = rowElement->Next;
	}
	LcdClear();
	// Якщо існує меню parent , формуємо заголовок текстом меню parent
	if (CurrState->Parent != (void*) &NULL_ENTRY) {
		RECT_SET(rec, 0, 0, LCD_X_RES - 1, rowHeight);
		parElement = CurrState->Parent;
		LcdDrawText(rec, DT_CENTER | DT_VCENTER, *fontMenu, lcdMode, parElement->Text);
		// Лінія розділення заголовка і списку
		LcdDrawLine(LCD_X_RES - 1, 0, rowHeight - 1, rowHeight - 1, lcdMode);
		//Вертикальна лінія прокрутки
		LcdDrawLine(LCD_X_RES - 1, LCD_X_RES - 1, rowHeight, LCD_Y_RES - 1, lcdMode);
		/* Малюємо повзунок прокрутки */
		slideStart = rowHeight;
		slideHeight = LCD_Y_RES - 1 - slideStart;
		if (numberRow >= numberItem)
			slideHeight = LCD_Y_RES - 1 - slideStart;
		else {
			slideHeight = (slideHeight * (numberRow - 1)) / numberItem;
			if (LCD_Y_RES % (numberRow - 1))
				slideHeight++;
			if (slideHeight < 4)
				slideHeight = 4;
			i = (LCD_Y_RES - slideStart - slideHeight) / (numberItem - 1);  //крок зсуву повзунка
			slideStart = slideStart + (i * (currItem - 1));
		}
		RECT_SET(rec, LCD_X_RES - 4, slideStart, 3, slideHeight);
		LcdDrawRect(rec, lcdMode);
		i = 1;
	} else {
		//Вертикальна лінія прокрутки
		LcdDrawLine(LCD_X_RES - 1, LCD_X_RES - 1, 0, LCD_Y_RES - 1, lcdMode);
		/* Малюємо повзунок прокрутки */
		slideStart = 0;
		slideHeight = LCD_Y_RES;
		if (numberRow >= numberItem)
			slideHeight = LCD_Y_RES - 1 - slideStart;
		else {
			slideHeight = (slideHeight * numberRow) / numberItem;
			if (LCD_X_RES % numberRow)
				slideHeight++;
			if (slideHeight < 4)
				slideHeight = 4;
			i = (LCD_Y_RES - slideStart - slideHeight) / (numberItem - 1);  //крок зсуву повзунка
			slideStart = slideStart + (i * (currItem - 1));
		}
		RECT_SET(rec, LCD_X_RES - 4, slideStart, 3, slideHeight);
		LcdDrawRect(rec, lcdMode);
		i = 0;
	}
	for (; i <= numberRow; i++) {
		RECT_SET(rec, 0, i * rowHeight, LENGTH_MENU_STRING, rowHeight);
		if (rowElement == CurrState) {
			n = (lcdMode == LCD_MODE_NORM) ? LCD_MODE_INVERSE : LCD_MODE_NORM;
		} else
			n = lcdMode;
		if(rowElement->Text[0] == '#')
			LcdDrawText(rec, DT_LEFT | DT_VCENTER, *fontMenu, n, rowElement->data->text);
		else LcdDrawText(rec, DT_LEFT | DT_VCENTER, *fontMenu, n, rowElement->Text);
		/* Mode select */
		if (mode == MENU_MODE_SELECT) {
			LcdDrawFrame((LENGTH_MENU_STRING - rowHeight - 2), (LENGTH_MENU_STRING - 5),
					(i * rowHeight) + 1, (i * rowHeight) + rowHeight - 2, n);
			if (rowElement->data->flag) {
				RECT_SET(rec, (LENGTH_MENU_STRING - rowHeight - 1), (i * rowHeight) + 2,
						rowHeight - 4, fontMenu->chars['$'].image->height);
				LcdDrawText(rec, DT_CENTER | DT_VCENTER, *fontMenu, n, "$");
			}
		}
		if (rowElement->Next != (void*) &NULL_ENTRY)
			rowElement = rowElement->Next;
		else
			return;
	}
}

void LcdMenuList(void) {
	LcdDrawMenu(MENU_MODE_LIST);
}
void LcdMenuSelect(void) {
	LcdDrawMenu(MENU_MODE_SELECT);
}

void LcdDrawOneItem(void) {
	rect_t rec;
	stateElement* parElem = 0;
	stateElement* parElem1 = 0;
	uint8_t rowHeight, i;
	uint8_t x, y, width, height;
	uint8_t chr = ' ';
	const tFont* itemFont;
	char* ch = 0;
	int16_t* data;
	if (CurrState->Parent != (void*) &NULL_ENTRY)
	{
		parElem = CurrState->Parent;
		if (parElem->Parent != (void*) &NULL_ENTRY)
			parElem1 = parElem->Parent;
	}
	rowHeight = fontMenu->chars[0].image->height + 4;  // висота рядка
	RECT_SET(rec, 0, 0, LCD_X_RES - 1, rowHeight);
	LcdClear();
	/* Текст діда */
	if((stateElement*)parElem1)
		LcdDrawText(rec, DT_CENTER | DT_VCENTER, *fontMenu, lcdMode, parElem1->Text);
	else LcdDrawText(rec, DT_CENTER | DT_VCENTER, *fontMenu, lcdMode, CurrState->Text);
	LcdDrawFrame(0, LCD_X_RES - 1, rowHeight, LCD_Y_RES - 1, lcdMode);
	y = rowHeight + 3;
	RECT_SET(rec, 1, y, LCD_X_RES - 3, rowHeight);
	/* Текст тата */
	if((stateElement*)parElem)
		LcdDrawText(rec, DT_CENTER | DT_VCENTER, *fontMenu, lcdMode, parElem->Text);
	y += rowHeight;
	/* Відображення дня тиждня під час показу дати*/
	/* if (CurrState == (stateElement*) &itemDate) { */
	/* 	RECT_SET(rec, 1, y, LCD_X_RES - 3, rowHeight); */
	/* 	chr = WeekDay(timeBufferInt[YEAR], timeBufferInt[MONTH], timeBufferInt[DAY]); */
	/* 	LcdDrawText(rec, DT_CENTER | DT_VCENTER, *fontMenu, lcdMode, dayOfWeek[chr]); */
	/* 	y += rowHeight; */
	/* } */
	if (CurrState->data->flag != 0) {
		if (CurrState->data->data != 0) {
			itemFont = *CurrState->data->font;
			/* Якщо дані містять текст */
			if (CurrState->data->flag & MENU_ITEM_TEXT) {
				ch = CurrState->data->data;  //визначаємо вказівник на текст
			} else {
				/* Якщо цифрова інформація */
				data = CurrState->data->data;  // вибираємо значення
				chr = (CurrState->data->flag & COMMA) ? COMMA : NO_COMMA;
				VariableToLcd(data, diagnosticChar, chr);  // перетворємо значення для відображення на дисплеї
				ch = diagnosticChar;  //масив з перетвореним значенням	
			}
			width = 0;
			//Визначаємо довжину слова з проміжками між символами
			for (i = 0; ch[i] != 0 && ch[i] != '\r'; i++) {
				chr = ch[i] - itemFont->chars[0].code;
				width += itemFont->chars[chr].image->width;
			}
			/* Додаємо проміжки між буквами (їх на один менше , ніж символів) */
			width += i;
			/* Визначаємо координати розміщення тексту */
			x = (LCD_X_RES - width) / 2;
			height = itemFont->chars[0].image->height;
			y = (LCD_Y_RES - height - y - 1) / 2 + y;
			for (i = 0; ch[i] != 0; i++) {
				/* Для меню налаштувань параметра (годиника , дати)
				 * визначаємо позицію параметра для налаштування 
				 * з коду тексту поточного меню 
				 * і робимо його блимаючим */
				if (CurrState->data->flag & MENU_ITEM_SETTING) {
					height = CurrState->Text[2] - '0';
					rowHeight = CurrState->Text[3] - '0';
					if (i == height || i == rowHeight) {
						if (ticksBlink)
							chr = ' ';
						else
							chr = ch[i];
					} else chr = ch[i];
				} else chr = ch[i];  // для всіх інших звичайне відображення
				width = LcdDrawChar(x, y, *itemFont, lcdMode, chr);
				x = x + width + 1;
			}
			/* Дописуємо текст після цифрового значення */
			/* if (CurrState->Text != NULL_TEXT && (CurrState->data->flag & MENU_ITEM_SETTING) == 0) { */
			/* 	height = (fontMenu->chars[0].image->height * 2) + 3; */
			/* 	y = y + itemFont->chars[0].image->height - height; */
			/* 	RECT_SET(rec, x, y, LCD_X_RES - x, height); */
			/* 	LcdDrawStrTwoRow(rec, *fontMenu, (char*) &CurrState->Text); */
			/* } */
		}
	}
}

void LcdSetClock(void) {
	/* timeCounter = RTC_GetCounter(); */
	/* RTC_TimeToLcd(); */
	LcdDrawOneItem();
}

/**
 * @name LcdDrawStrTooRow
 * @param rec -> rectangle for draw
 * @param str -> pointer to string
 */
void LcdDrawStrTwoRow(rect_t rec, tFont font, char* str) {
	/* uint8_t x, y, length, width; */
	/* lengStr_t ls; */
	/* #<{(| Визначаємо довжину тексту в пікселах |)}># */
	/* LcdGetStrWidth(&ls, font, str); */
	/* y = rec.y + rec.height - font.chars[0].image->height;  // позиція -y для нижнього рядка тексту */
	/* length = ls.length1;  // довжина нижнього тексту при одному рядку */
	/* if (ls.length2) {  // якщо два рядки  */
	/* 	y -= (font.chars[0].image->height + 3);  // зсуваємо позицію -у вгору */
	/* 	x = rec.x + ((rec.length - ls.length1) / 2);  // і визначаємо позицію -х */
	/* 	while (*str != '\n') {  // виводимо текст до символу '\n' */
	/* 		width = LcdDrawChar(x, y, font, lcdMode, *str); */
	/* 		x = x + width + 1; */
	/* 		str++; */
	/* 	} */
	/* 	#<{(| Визначаємо довжину лінії для розділу рядків |)}># */
	/* 	#<{(| Вибираємо по більшій довжині тексту з двох рядків |)}># */
	/* 	if (ls.length1 > ls.length2) */
	/* 		length = ls.length1; */
	/* 	else */
	/* 		length = ls.length2; */
	/* 	x = rec.x + ((rec.length - length) / 2); */
	/* 	y += (font.chars[0].image->height + 1); */
	/* 	LcdDrawLine(x, x + length, y, y, lcdMode); */
	/* 	length = ls.length2;  // довжина тексту нижнього рядка при двох рядках тексту */
	/* 	y += 2;  // позиція -у для нижнього рядка */
	/* } */
	/* x = rec.x + ((rec.length - length) / 2); */
	/* while (*str) { */
	/* 	width = LcdDrawChar(x, y, font, lcdMode, *str); */
	/* 	x = x + width + 1; */
	/* 	str++; */
	/* } */
}

void VariableToLcd(int16_t* data, char resChar[], uint8_t comma) {
	int16_t tempData = *data;
	if (tempData & 0x8000)
	{
		resChar[0] = '-';
		tempData = 0xFFFF - tempData;
	}
	else
		resChar[0] = ' ';
	if (tempData > 100) {
		resChar[1] = tempData / 100 + '0';
		resChar[2] = (tempData / 10) % 10 + '0';
		if (comma == COMMA) {
			resChar[3] = '.';
			resChar[4] = tempData % 10 + '0';
			resChar[5] = 0;
		} else {
			resChar[3] = tempData % 10 + '0';
			resChar[4] = 0;
		}
	} else {
		if (tempData < 100) {
			resChar[1] = resChar[0];
			resChar[0] = ' ';
			resChar[2] = tempData / 10 + '0';
			if (comma == COMMA) {
				resChar[3] = '.';
				resChar[4] = tempData % 10 + '0';
				resChar[5] = 0;
			} else {
				resChar[3] = tempData % 10 + '0';
				resChar[4] = 0;
			}
		} else {
			if (tempData < 10) {
				resChar[2] = resChar[0];
				resChar[0] = ' ';
				resChar[1] = ' ';
				if (comma == COMMA) {
					resChar[3] = '0';
					resChar[4] = tempData % 10 + '0';
					resChar[5] = 0;
				} else {
					resChar[3] = tempData % 10 + '0';
					resChar[4] = 0;
				}
			}
		}
	}
}
