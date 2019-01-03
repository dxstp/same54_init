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
#include "gclk.h"

void init_gclk(void) {
	// GCLK0: source is FDPLL0, no divisor
	// for main clock
	GCLK->GENCTRL[0].reg =
	(1 << GCLK_GENCTRL_GENEN_Pos)
	| GCLK_GENCTRL_SRC_DPLL0;

	// GLCK1: source is FDPLL1, divided by 200, Output enabled (PB15)
	// to assert right PLL clocking
	GCLK->GENCTRL[1].reg =
	GCLK_GENCTRL_DIV(200)
	| (1 << GCLK_GENCTRL_GENEN_Pos)
	| (1 << GCLK_GENCTRL_OE_Pos)
	| GCLK_GENCTRL_SRC_DPLL1;
	
	// GLCK2: source is FDPLL1, divided by 2
	// for PWM TC7 (max 100 MHz)
	GCLK->GENCTRL[2].reg =
	GCLK_GENCTRL_DIV(2)
	| (1 << GCLK_GENCTRL_GENEN_Pos)
	| GCLK_GENCTRL_SRC_DPLL1;

	// GLCK3: source is XOSC1
	// for SERCOM
	GCLK->GENCTRL[3].reg =
	GCLK_GENCTRL_DIV(1)
	| (1 << GCLK_GENCTRL_GENEN_Pos)
	| GCLK_GENCTRL_SRC_XOSC1;

	//GCLK4: source is internal 32K
	GCLK->GENCTRL[4].reg = 
	GCLK_GENCTRL_DIV(1)
	| (1 << GCLK_GENCTRL_GENEN_Pos)
	| GCLK_GENCTRL_SRC_OSCULP32K;
}