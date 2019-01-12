// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#include <sam.h>
#include "gpio.h"

/**
 * \brief Macros for the pin and port group, lower 5
 * bits stands for pin number in the group, higher 3
 * bits stands for port group
 */

enum gpio_port { GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PORTD, GPIO_PORTE };

/**
 * init the GPIO module
 */
void GPIO_init(void) {
	
	// hold down RC21 to disable PHY for correct power-down readings
	// hw fix: remove R602, replace C613 with 100k resistor
	PORT->Group[GPIO_PORTC].DIRSET.reg = (1 << 21);
	PORT->Group[GPIO_PORTC].OUTCLR.reg = (1 << 21);
	
	// enable AD input on PB04
	PORT->Group[GPIO_PORTB].WRCONFIG.reg = 
		  PORT_WRCONFIG_PMUX(MUX_PB04B_ADC1_AIN6)
		| PORT_WRCONFIG_WRPINCFG
		| PORT_WRCONFIG_PMUXEN
		| ((1 << 4) & 0xffff);
	
	// enable AD input on PB05	
	PORT->Group[GPIO_PORTB].WRCONFIG.reg =
		PORT_WRCONFIG_PMUX(MUX_PB05B_ADC1_AIN7)
		| PORT_WRCONFIG_WRPINCFG
		| PORT_WRCONFIG_PMUXEN
		| ((1 << 5) & 0xffff);
	
}