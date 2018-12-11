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
// start external 32k crystal
// set RTC to external 32k crystal
void init_oscctrl(void) {
	OSCCTRL->XOSCCTRL[1].reg =
		  OSCCTRL_XOSCCTRL_IMULT(4)
		| OSCCTRL_XOSCCTRL_IPTAT(3)
		| (1 << OSCCTRL_XOSCCTRL_XTALEN_Pos)
		| (1 << OSCCTRL_XOSCCTRL_ENABLE_Pos);
	
	while(!(OSCCTRL->INTFLAG.reg & OSCCTRL_INTFLAG_XOSCRDY1));
	
	OSC32KCTRL->XOSC32K.reg = 
		  OSC32KCTRL_XOSC32K_ENABLE
		| OSC32KCTRL_XOSC32K_XTALEN;

	while(!(OSC32KCTRL->INTFLAG.reg & OSC32KCTRL_INTFLAG_XOSC32KRDY));

	OSC32KCTRL->RTCCTRL.reg = 
		OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K;
}