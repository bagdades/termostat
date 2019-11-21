/************************************************************************/
/*                                                                      */
/*        Access Dallas 1-Wire Device with ATMEL AVRs                   */
/*                                                                      */
/*              Author: Peter Dannegger                                 */
/*                      danni@specs.de                                  */
/*                                                                      */
/* modified by Martin Thomas <eversmith@heizung-thomas.de> 9/2004       */
/************************************************************************/

#include "stm32f1xx_hal.h"

#include "dwt_stm32_delay.h"
#include "onewire.h"


#define OW_GET_IN()   ( GPIOA->IDR & GPIO_IDR_IDR7)
#define OW_OUT_LOW()  ( GPIOA->BRR |= GPIO_BRR_BR7)
#define OW_OUT_HIGH() ( GPIOA->BSRR |= GPIO_BSRR_BS7)
#define OW_DIR_IN()   ( GPIOA->CRL &= ~GPIO_CRL_MODE7 )
#define OW_DIR_OUT()  ( GPIOA->CRL |= GPIO_CRL_MODE7 )

void OW_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA->CRL &= ~(GPIO_CRL_CNF7 | GPIO_CRL_MODE7);
	GPIOA->CRL |= GPIO_CRL_CNF7_0;
}

uint8_t OW_InputPinState() {
	return OW_GET_IN();
}

void OW_ParasiteEnable(void) {
	OW_OUT_HIGH();
	OW_DIR_OUT();
}

void OW_ParasiteDisable(void) {
	OW_OUT_LOW();
	OW_DIR_IN();
}

uint8_t OW_Reset(void) {
	uint8_t err;

	OW_OUT_LOW(); // disable internal pull-up (maybe on from parasite)
	OW_DIR_OUT(); // pull OW-Pin low for 480us

	OW_DELAY(480);


	// set Pin as input - wait for clients to pull low
	OW_DIR_IN(); // input

	OW_DELAY(66);
	err = OW_GET_IN(); // no presence detect
	// nobody pulled to low, still high

	// after a delay the clients should release the line
	// and input-pin gets back to high due to pull-up-resistor
	OW_DELAY(480 - 66);
	if (OW_GET_IN() == 0) // short circuit
		err = 1;

	return err;
}

/* Timing issue when using runtime-bus-selection (!OW_ONE_BUS):
 The master should sample at the end of the 15-slot after initiating
 the read-time-slot. The variable bus-settings need more
 cycles than the constant ones so the delays had to be shortened 
 to achive a 15uS overall delay 
 Setting/clearing a bit in I/O Register needs 1 cyle in OW_ONE_BUS
 but around 14 cyles in configureable bus (us-Delay is 4 cyles per uS) */
uint8_t OW_BitIO(uint8_t b) {


	OW_DIR_OUT(); // drive bus low

	OW_DELAY(1); // Recovery-Time wuffwuff was 1
	if (b)
		OW_DIR_IN(); // if bit is 1 set bus high (by ext. pull-up)

	// wuffwuff delay was 15uS-1 see comment above
	OW_DELAY(15 - 1);

	if (OW_GET_IN() == 0)
		b = 0; // sample at end of read-timeslot

	OW_DELAY(60 - 15);
	OW_DIR_IN();

	return b;
}

uint8_t OW_ByteWR(uint8_t b) {
	uint8_t i = 8, j;
	do {
		j = OW_BitIO(b & 1);
		b >>= 1;
		if (j)
			b |= 0x80;
	} while (--i);
	return b;
}

uint8_t OW_ByteRD(void) { // read by sending 0xff (a dontcare?)
	return OW_ByteWR(0xFF);
}

uint8_t OW_RomSearch(uint8_t diff, uint8_t *id) {
	uint8_t i, j, next_diff;
	uint8_t b;

	if (OW_Reset())
		return OW_PRESENCE_ERR; // error, no device found

	OW_ByteWR(OW_SEARCH_ROM); // ROM search command
	next_diff = OW_LAST_DEVICE; // unchanged on last device

	i = OW_ROMCODE_SIZE * 8; // 8 bytes
	do {
		j = 8; // 8 bits
		do {
			b = OW_BitIO(1); // read bit
			if (OW_BitIO(1)) { // read complement bit
				if (b) // 11
					return OW_DATA_ERR; // data error
			} else {
				if (!b) { // 00 = 2 devices
					if (diff > i || ((*id & 1) && diff != i)) {
						b = 1; // now 1
						next_diff = i; // next pass 0
					}
				}
			}
			OW_BitIO(b); // write bit
			*id >>= 1;
			if (b)
				*id |= 0x80; // store bit
			i--;
		} while (--j);
		id++; // next byte
	} while (i);
	return next_diff; // to continue search
}

/**
 * @brief send command to 1-wire device
 * @param command
 * @param id
 */
void OW_Command(uint8_t command, uint8_t *id) {
	uint8_t i;

	OW_Reset();
	if (id) {
		OW_ByteWR(OW_MATCH_ROM); // to a single device
		i = OW_ROMCODE_SIZE;
		do {
			OW_ByteWR(*id);
			id++;
		} while (--i);
	} else
		OW_ByteWR(OW_SKIP_ROM); // to all devices

	OW_ByteWR(command);
}
