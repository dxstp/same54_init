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
#include "dpll.h"

void dpll_init(void) {
	
	// ****** DPLL0 ****** //
	// divide XOSC1 clock (12 MHz) by 4 (max input is 3.2 MHz!)
	OSCCTRL->Dpll[0].DPLLCTRLB.reg = OSCCTRL_DPLLCTRLB_DIV(1) | OSCCTRL_DPLLCTRLB_REFCLK(0x03);
	printf("DPLL0   -- set reference to XOSC1 and divide by 4.\r\n");
	
	// this register is write-synchronized, wait for syncbusy to clear
	OSCCTRL->Dpll[0].DPLLRATIO.reg = OSCCTRL_DPLLRATIO_LDR(39);
	while(OSCCTRL->Dpll[0].DPLLSYNCBUSY.bit.DPLLRATIO);
	printf("DPLL0   -- set multiplier to 40.\r\n");
	
	OSCCTRL->Dpll[0].DPLLCTRLA.reg = OSCCTRL_DPLLCTRLA_ENABLE;
	while(OSCCTRL->Dpll[0].DPLLSYNCBUSY.bit.ENABLE);
	while(!(OSCCTRL->Dpll[0].DPLLSTATUS.bit.LOCK || OSCCTRL->Dpll[0].DPLLSTATUS.bit.CLKRDY));
	printf("DPLL0   -- enable DPLL0 and wait for lock.\r\n");
	
	// ****** DPLL1 ****** //
	OSCCTRL->Dpll[1].DPLLCTRLB.reg = OSCCTRL_DPLLCTRLB_DIV(2) | OSCCTRL_DPLLCTRLB_REFCLK(0x03);
	printf("DPLL1   -- set reference to XOSC1 and divide by 6.\r\n");
	
	OSCCTRL->Dpll[1].DPLLRATIO.reg = OSCCTRL_DPLLRATIO_LDR(99);
	while(OSCCTRL->Dpll[1].DPLLSYNCBUSY.bit.DPLLRATIO);
	printf("DPLL1   -- set multiplier to 100.\r\n");
	
	OSCCTRL->Dpll[1].DPLLCTRLA.reg = OSCCTRL_DPLLCTRLA_ENABLE;
	while(OSCCTRL->Dpll[1].DPLLSYNCBUSY.bit.ENABLE);
	while(!(OSCCTRL->Dpll[1].DPLLSTATUS.bit.LOCK || OSCCTRL->Dpll[1].DPLLSTATUS.bit.CLKRDY));
	printf("DPLL1   -- enable DPLL1 and wait for lock.\r\n");
}