/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include <sam.h>
#include <stdio.h>
#include "uart.h"



#define CONF_SERCOM_2_USART_BAUD_RATE 115200
#define CONF_SERCOM_2_USART_BAUD_RATE_REGISTER_VAL (65536 - ((65536 * 16.0f * (CONF_SERCOM_2_USART_BAUD_RATE)) / 12000000))

void uart_init(void) {

	// unmask SERCOM2 in MCLK to enable clock to user interface
	MCLK->APBBMASK.reg |= MCLK_APBBMASK_SERCOM2;
	
	// connect GLCK3 with SERCOM2 module (core and slow clock)
	GCLK->PCHCTRL[SERCOM2_GCLK_ID_CORE].reg = GCLK_PCHCTRL_GEN_GCLK3 | (1 << GCLK_PCHCTRL_CHEN_Pos);
	GCLK->PCHCTRL[SERCOM2_GCLK_ID_SLOW].reg = GCLK_PCHCTRL_GEN_GCLK4 | (1 << GCLK_PCHCTRL_CHEN_Pos);
	
	// do a software reset of the module (write-synchronized)
	SERCOM2->USART.CTRLA.reg = SERCOM_USART_CTRLA_SWRST;
	while (SERCOM2->USART.SYNCBUSY.reg & SERCOM_USART_SYNCBUSY_SWRST);

	// configure UART mode and bit order
	SERCOM2->USART.CTRLA.reg = 
		  SERCOM_USART_CTRLA_MODE(1)
		| SERCOM_USART_CTRLA_RXPO(1)
		| SERCOM_USART_CTRLA_DORD;

	// enable transmitter and receiver
	SERCOM2->USART.CTRLB.reg = 
		  SERCOM_USART_CTRLB_TXEN
		| SERCOM_USART_CTRLB_RXEN;
	while(SERCOM2->USART.SYNCBUSY.reg & SERCOM_USART_SYNCBUSY_CTRLB);

	// setup baud rate
	SERCOM2->USART.BAUD.reg = CONF_SERCOM_2_USART_BAUD_RATE_REGISTER_VAL;

	// enable UART
	SERCOM2->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;
	while(SERCOM2->USART.SYNCBUSY.reg & SERCOM_USART_SYNCBUSY_ENABLE);

	// set STDIO to unbuffered
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
}

int32_t stdio_io_write(const uint8_t *const buf, const uint16_t length) {
	uint32_t offset = 0;
	
	while(!(SERCOM2->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_DRE));
	
	do {
		SERCOM2->USART.DATA.reg = buf[offset];
		while(!(SERCOM2->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_DRE));
	} while (++offset < length);
	
	while(!(SERCOM2->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_TXC));
	
	return (int32_t)offset;
}

int32_t stdio_io_read(uint8_t *const buf, const uint16_t length) {
	uint32_t offset = 0;
	
	do {
		while(!(SERCOM2->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_RXC));
		buf[offset] = SERCOM2->USART.DATA.reg;
	} while (++offset < length);

	return (int32_t)offset;
}


int _read(int file, char *ptr, int len) {
	int n = 0;

	if (file != 0) {
		return -1;
	}

	n = stdio_io_read((uint8_t *)ptr, len);
	if (n < 0) {
		return -1;
	}

	return n;
}

int _write(int file, char *ptr, int len) {
	int n = 0;

	if ((file != 1) && (file != 2) && (file != 3)) {
		return -1;
	}

	n = stdio_io_write((const uint8_t *)ptr, len);
	if (n < 0) {
		return -1;
	}

	return n;
}