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
#include <stdio.h>
#include "dpll.h"

/**
 * init DPLL0 and DPLL1
 * clock input is XOSC1, which will by divided by 4 beforehand
 * maximum clock input frequency is 3 MHz
 */
void DPLL_init(void) {
	
	// ****** DPLL0 ****** //
	// divide XOSC1 clock (12 MHz) by 4 (max input is 3.2 MHz!)
	OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLCTRLB =
            OSCCTRL_DPLLCTRLB_DIV(1) 
          | OSCCTRL_DPLLCTRLB_REFCLK(OSCCTRL_DPLLCTRLB_REFCLK_XOSC1_Val);
	printf("DPLL0   -- set reference to XOSC1 and divide by 4.\r\n");
	
	// this register is write-synchronized, wait for syncbusy to clear
	OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLRATIO = OSCCTRL_DPLLRATIO_LDR(39);
	while(OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLSYNCBUSY & OSCCTRL_DPLLSYNCBUSY_DPLLRATIO_Msk);
	printf("DPLL0   -- set multiplier to 40.\r\n");
	
	OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLCTRLA = OSCCTRL_DPLLCTRLA_ENABLE(1);
	while(OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLSYNCBUSY & OSCCTRL_DPLLSYNCBUSY_Msk);
	while(!(
            (OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLSTATUS & OSCCTRL_DPLLSTATUS_LOCK_Msk)
         || (OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLSTATUS & OSCCTRL_DPLLSTATUS_CLKRDY_Msk)
           ));
	printf("DPLL0   -- enable DPLL0 and wait for lock.\r\n");
	
	// ****** DPLL1 ****** //
	OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLCTRLB = 
            OSCCTRL_DPLLCTRLB_DIV(2) 
          | OSCCTRL_DPLLCTRLB_REFCLK(OSCCTRL_DPLLCTRLB_REFCLK_XOSC1_Val);
	printf("DPLL1   -- set reference to XOSC1 and divide by 6.\r\n");
	
	OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLRATIO = OSCCTRL_DPLLRATIO_LDR(99);
	while(OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLSYNCBUSY & OSCCTRL_DPLLSYNCBUSY_DPLLRATIO_Msk);
	printf("DPLL1   -- set multiplier to 100.\r\n");
	
	OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLCTRLA = OSCCTRL_DPLLCTRLA_ENABLE(1);
	while(OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLSYNCBUSY & OSCCTRL_DPLLSYNCBUSY_ENABLE_Msk);
	while(!(
            (OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLSTATUS & OSCCTRL_DPLLSTATUS_LOCK_Msk)
         || (OSCCTRL_REGS->DPLL[1].OSCCTRL_DPLLSTATUS & OSCCTRL_DPLLSTATUS_CLKRDY_Msk)
           ));
	printf("DPLL1   -- enable DPLL1 and wait for lock.\r\n");
}