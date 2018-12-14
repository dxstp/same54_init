/*
 * rtc.c
 *
 * Created: 12.12.2018 20:24:57
 *  Author: M19931
 */ 

#include <sam.h>
#include <stdint.h>
#include <stdio.h>
#include "rtc.h"

void init_rtc(void) {

	OSC32KCTRL->RTCCTRL.reg = OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K;
	printf("OSC32K  -- select internal 32kHz oscillator as source.\r\n");
	
	RTC->MODE0.CTRLA.reg = RTC_MODE0_CTRLA_SWRST;
	while(RTC->MODE0.SYNCBUSY.bit.SWRST);
	while(RTC->MODE0.CTRLA.bit.SWRST);
	printf("RTC     -- software reset.\r\n");
	
	RTC->MODE0.CTRLA.reg = 
		  RTC_MODE0_CTRLA_COUNTSYNC
		| RTC_MODE0_CTRLA_PRESCALER_DIV1
		| RTC_MODE0_CTRLA_MATCHCLR;
	while(RTC->MODE0.SYNCBUSY.bit.COUNTSYNC);
	printf("RTC     -- enable read synchronization for count register.\r\n");
	printf("RTC     -- set divider to 1.\r\n");
	printf("RTC     -- enable clear on match.\r\n");
	
	RTC->MODE0.EVCTRL.bit.CMPEO0 = 1;
	printf("RTC     -- enable event CMP0, will set intflag on match.\r\n");
	
	RTC->MODE0.COMP[0].reg = 32768;
	printf("RTC     -- set compare value to 32768.\r\n");
		
	RTC->MODE0.CTRLA.reg |= RTC_MODE0_CTRLA_ENABLE;
	while(RTC->MODE0.SYNCBUSY.bit.ENABLE);
	printf("RTC     -- enable RTC.\r\n");
	
	RTC->MODE0.INTENSET.bit.CMP0 = 1;
	printf("RTC     -- enable interrupt for CMP0.\r\n");
}