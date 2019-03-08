// DOM-IGNORE-BEGIN
/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. 
    
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

#include <xc.h>
#include "gclk.h"

/**
 * connect GCLK0 to DPLL0 (120 MHz)
 * connect GCLK1 to DPLL1 (200 MHz), divide by 200 => 1 MHz for Pin Output (to check clock)
 * connect GCLK2 to DPLL1 (200 MHz), divide by 2 => 100 MHz for PWM
 * connect GCLK3 to XOSC1 (12 MHz) => 12 MHz for SERCOM core
 * connect GCLK4 to XOSC32K (32.768 kHz) => for RTC and SERCOM slow
 */
void GCLK_init(void) {
	// GCLK0: source is FDPLL0, no divisor
	// for main clock
	GCLK_REGS->GCLK_GENCTRL[0] =
		  GCLK_GENCTRL_GENEN(1)
		| GCLK_GENCTRL_SRC_DPLL0;

	// GLCK1: source is FDPLL1, divided by 200, Output enabled (PB15)
	// to assert right PLL clocking with an output pin
	GCLK_REGS->GCLK_GENCTRL[1] =
		  GCLK_GENCTRL_GENEN(1)
		| GCLK_GENCTRL_DIV(200)
		| GCLK_GENCTRL_OE(1)
		| GCLK_GENCTRL_SRC_DPLL1;
	
	// GLCK2: source is FDPLL1, divided by 2
	// for PWM TC7 (max 100 MHz)
	GCLK_REGS->GCLK_GENCTRL[2] =
		  GCLK_GENCTRL_GENEN(1)
		| GCLK_GENCTRL_DIV(2)
		| GCLK_GENCTRL_SRC_DPLL1;

	// GLCK3: source is XOSC1
	// for SERCOM
	GCLK_REGS->GCLK_GENCTRL[3] =
		  GCLK_GENCTRL_GENEN(1)
		| GCLK_GENCTRL_DIV(1)
		| GCLK_GENCTRL_SRC_XOSC1;

	//GCLK4: source is internal 32K
	GCLK_REGS->GCLK_GENCTRL[4] =
		  GCLK_GENCTRL_GENEN(1)
		| GCLK_GENCTRL_DIV(1)
		| GCLK_GENCTRL_SRC_OSCULP32K;
}