/*
 * dpll.c
 *
 * Created: 26.11.2018 14:41:34
 *  Author: M19931
 */ 

#include "same54.h"
#include "dpll.h"

void init_dpll(void) {
	// FDPLL0: ref is XOSC1 (0x03), divided by 4 (max input is 3.2 MHz!)
	// divider is fosc/(2 × (DIV + 1)) -> DIV is 1
	// Multiplier is 40 (3*40 = 120) -> LDR is 39
	// for main clock
	OSCCTRL->Dpll[0].DPLLRATIO.reg = OSCCTRL_DPLLRATIO_LDR(39);
	
	// this register is write-synchronized, wait until the
	// corresponding syncbusy bit clears
	while(OSCCTRL->Dpll[0].DPLLSYNCBUSY.reg & OSCCTRL_DPLLSYNCBUSY_MASK);
	
	// divide XOSC clock by 4
	OSCCTRL->Dpll[0].DPLLCTRLB.reg =
	OSCCTRL_DPLLCTRLB_DIV(1)
	| OSCCTRL_DPLLCTRLB_REFCLK(0x03);
	
	OSCCTRL->Dpll[0].DPLLCTRLA.reg = 1 << OSCCTRL_DPLLCTRLA_ENABLE_Pos;
	
	while(OSCCTRL->Dpll[0].DPLLSYNCBUSY.reg & OSCCTRL_DPLLSYNCBUSY_MASK);

	// wait for PLL to lock
	while(!(
		   ((OSCCTRL->Dpll[0].DPLLSTATUS.reg & OSCCTRL_DPLLSTATUS_LOCK) >> OSCCTRL_DPLLSTATUS_LOCK_Pos)
		|| ((OSCCTRL->Dpll[0].DPLLSTATUS.reg & OSCCTRL_DPLLSTATUS_CLKRDY) >> OSCCTRL_DPLLSTATUS_CLKRDY_Pos)
		));
	
	
	// FDPLL1: ref is XOSC1 (0x03), divided by 6 (max input is 3.2 MHz!)
	// divider is fosc/(2 × (DIV + 1)) -> DIV is 2
	// Multiplier is 100 (2*100 = 200) -> LDR is 99
	// for peripherals (will be divided down as needed)
	OSCCTRL->Dpll[1].DPLLRATIO.reg = OSCCTRL_DPLLRATIO_LDR(99);
	
	while(OSCCTRL->Dpll[1].DPLLSYNCBUSY.reg & OSCCTRL_DPLLSYNCBUSY_MASK);
	
	OSCCTRL->Dpll[1].DPLLCTRLB.reg =
	OSCCTRL_DPLLCTRLB_DIV(2)
	| OSCCTRL_DPLLCTRLB_REFCLK(0x03);
	
	OSCCTRL->Dpll[1].DPLLCTRLA.reg = 1 << OSCCTRL_DPLLCTRLA_ENABLE_Pos;
	
	while(OSCCTRL->Dpll[1].DPLLSYNCBUSY.reg & OSCCTRL_DPLLSYNCBUSY_MASK);

	// wait for PLL to lock
	while(!(
		   ((OSCCTRL->Dpll[1].DPLLSTATUS.reg & OSCCTRL_DPLLSTATUS_LOCK) >> OSCCTRL_DPLLSTATUS_LOCK_Pos)
		|| ((OSCCTRL->Dpll[1].DPLLSTATUS.reg & OSCCTRL_DPLLSTATUS_CLKRDY) >> OSCCTRL_DPLLSTATUS_CLKRDY_Pos)
		));
}