/*
 * pwm.c
 *
 * Created: 26.11.2018 19:44:09
 *  Author: M19931
 */ 

#include <sam.h>
#include <stdio.h>
#include "pwm.h"


void init_pwm(void) {
	MCLK->APBDMASK.reg |= MCLK_APBDMASK_TC7;
	printf("PWM     -- unmask TC7 to enable interface on APBD.\r\n");

	GCLK->PCHCTRL[TC7_GCLK_ID].reg = GCLK_PCHCTRL_GEN_GCLK2 | (1 << GCLK_PCHCTRL_CHEN_Pos);
	printf("PWM     -- connect GLCK2 to TC7.\r\n");
	
	// do a software reset of the module (write-synchronized)
	TC7->COUNT16.CTRLA.reg = TC_CTRLA_SWRST;
	while (TC7->COUNT16.SYNCBUSY.bit.SWRST);
	printf("PWM     -- issue a software reset.\r\n");
	
	TC7->COUNT16.CTRLA.reg = TC_CTRLA_MODE(TC_CTRLA_MODE_COUNT16_Val);
	TC7->COUNT16.WAVE.reg = TC_WAVE_WAVEGEN_NPWM_Val;
	printf("PWM     -- set mode to normal PWM in 16-bit counter mode.\r\n");
	
	TC7->COUNT16.CC[0].reg = 32767;
	while (TC7->COUNT16.SYNCBUSY.bit.CC0);
	TC7->COUNT16.CC[1].reg = 10000;
	while (TC7->COUNT16.SYNCBUSY.bit.CC1);
	printf("PWM     -- set initial duty cycles for CC0 and CC1.\r\n");
	
	TC7->COUNT16.CTRLA.reg |= TC_CTRLA_ENABLE;
	while (TC7->COUNT16.SYNCBUSY.bit.ENABLE);
	printf("PWM     -- enable TC7 module.\r\n");
}