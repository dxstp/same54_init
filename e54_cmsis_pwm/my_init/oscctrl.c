/*
 * oscctrl.c
 *
 * Created: 26.11.2018 13:53:49
 *  Author: M19931
 */ 

#include <sam.h>
#include "oscctrl.h"

// OSCCTRL: setup XOSC1 with 12 MHz
// multiplier and current according to table 28-7
void oscctrl_init(void) {
	OSCCTRL->XOSCCTRL[1].reg =
		  OSCCTRL_XOSCCTRL_IMULT(4)
		| OSCCTRL_XOSCCTRL_IPTAT(3)
		| (1 << OSCCTRL_XOSCCTRL_XTALEN_Pos)
		| (1 << OSCCTRL_XOSCCTRL_ENABLE_Pos);
	
	while(!(OSCCTRL->INTFLAG.bit.XOSCRDY1));
}