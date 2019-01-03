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