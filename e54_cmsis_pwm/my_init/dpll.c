/*
 * dpll.c
 *
 * Created: 26.11.2018 14:41:34
 *  Author: M19931
 */ 

#include <sam.h>
#include <stdio.h>
#include "dpll.h"

void init_dpll(void) {
	
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
	printf("DPLL0   -- enable DPLL1 and wait for lock.\r\n");
}