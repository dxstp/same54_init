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
	printf("OSC32K  -- select internal 32k oscillator as source.\r\n");
	
	RTC->MODE0.CTRLA.reg = RTC_MODE0_CTRLA_SWRST;
	while(RTC->MODE0.SYNCBUSY.bit.SWRST);
	while(RTC->MODE0.CTRLA.bit.SWRST);
	printf("RTC     -- software reset.\r\n");
	
	RTC->MODE0.CTRLA.reg = 
		  RTC_MODE0_CTRLA_COUNTSYNC
		| RTC_MODE0_CTRLA_PRESCALER_DIV1;
	while(RTC->MODE0.SYNCBUSY.bit.COUNTSYNC);
	printf("RTC     -- enable read synchronization for count register.\r\n");
	
	RTC->MODE0.EVCTRL.reg = RTC_MODE0_EVCTRL_PEREO1;
	printf("RTC     -- enable event PER1, will set intflag every 500µs (2048 Hz).\r\n");
	
	RTC->MODE0.CTRLA.reg |= RTC_MODE0_CTRLA_ENABLE;
	while(RTC->MODE0.SYNCBUSY.bit.ENABLE);
	printf("RTC     -- enable RTC.\r\n");
	
	while(!(RTC->MODE0.INTFLAG.bit.PER1));
	printf("RTC     -- PER1 event at %u\r\n", (unsigned int) RTC->MODE0.COUNT.reg);
}