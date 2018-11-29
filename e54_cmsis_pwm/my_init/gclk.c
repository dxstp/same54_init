/*
 * gclk.c
 *
 * Created: 26.11.2018 14:31:14
 *  Author: M19931
 */ 

#include "same54.h"
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
}