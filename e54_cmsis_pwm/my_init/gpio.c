/*
 * gpio.c
 *
 * Created: 26.11.2018 18:24:35
 *  Author: M19931
 */ 

#include "same54.h"
#include "gpio.h"

/**
 * \brief Macros for the pin and port group, lower 5
 * bits stands for pin number in the group, higher 3
 * bits stands for port group
 */

enum gpio_port { GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PORTD, GPIO_PORTE };


void init_gpio(void) {
	
	// set GLCK1 output
	//PORT->Group[GPIO_PORTB].OUTCLR.reg = (1 << 15);
	//PORT->Group[GPIO_PORTB].DIRSET.reg = (1 << 15);
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
		  PORT_WRCONFIG_PMUX(MUX_PB15M_GCLK_IO1) 
		| PORT_WRCONFIG_WRPMUX
		| PORT_WRCONFIG_PMUXEN
		| PORT_WRCONFIG_WRPINCFG
		| ((1 << 15) & 0xffff);
	
	// set PWM output
	//PORT->Group[GPIO_PORTB].DIRSET.reg = (1 << 0) | (1 << 1);
	//PORT->Group[GPIO_PORTB].OUTSET.reg = (1 << 0) | (1 << 1);
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
		  PORT_WRCONFIG_PMUX(MUX_PB00E_TC7_WO0)
		| PORT_WRCONFIG_WRPMUX
		| PORT_WRCONFIG_PMUXEN
		| PORT_WRCONFIG_WRPINCFG
		| ((1 << 0) & 0xffff);
		
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
		  PORT_WRCONFIG_PMUX(MUX_PB01E_TC7_WO1)
		| PORT_WRCONFIG_WRPMUX
		| PORT_WRCONFIG_PMUXEN
		| PORT_WRCONFIG_WRPINCFG
		| ((1 << 1) & 0xffff);
}