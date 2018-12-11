/*
 * gpio.c
 *
 * Created: 26.11.2018 18:24:35
 *  Author: M19931
 */ 

#include <sam.h>
#include "gpio.h"

/**
 * \brief Macros for the pin and port group, lower 5
 * bits stands for pin number in the group, higher 3
 * bits stands for port group
 */

enum gpio_port { GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PORTD, GPIO_PORTE };


void init_gpio(void) {
	
	// set GLCK1 output
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
		  PORT_WRCONFIG_PMUX(MUX_PB15M_GCLK_IO1) 
		| PORT_WRCONFIG_WRPMUX
		| PORT_WRCONFIG_PMUXEN
		| PORT_WRCONFIG_WRPINCFG
		| ((1 << 15) & 0xffff);
	
	// set PWM WO0 output
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
		  PORT_WRCONFIG_PMUX(MUX_PB00E_TC7_WO0)
		| PORT_WRCONFIG_WRPMUX
		| PORT_WRCONFIG_PMUXEN
		| PORT_WRCONFIG_WRPINCFG
		| ((1 << 0) & 0xffff);
	
	// set PWM WO1 output
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
		  PORT_WRCONFIG_PMUX(MUX_PB01E_TC7_WO1)
		| PORT_WRCONFIG_WRPMUX
		| PORT_WRCONFIG_PMUXEN
		| PORT_WRCONFIG_WRPINCFG
		| ((1 << 1) & 0xffff);

	// set UART RX input
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
		  PORT_WRCONFIG_PMUX(MUX_PB24D_SERCOM2_PAD1)
		| PORT_WRCONFIG_WRPMUX
		| PORT_WRCONFIG_PMUXEN
		| PORT_WRCONFIG_WRPINCFG
		| PORT_WRCONFIG_HWSEL
		| ((1 << 8) & 0xffff);

	// set UART TX output
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
	PORT_WRCONFIG_PMUX(MUX_PB25D_SERCOM2_PAD0)
	| PORT_WRCONFIG_WRPMUX
	| PORT_WRCONFIG_PMUXEN
	| PORT_WRCONFIG_WRPINCFG
	| PORT_WRCONFIG_HWSEL
	| ((1 << 9) & 0xffff);
}