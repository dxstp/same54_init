/*
 * pwm.c
 *
 * Created: 26.11.2018 19:44:09
 *  Author: M19931
 */ 

#include <sam.h>
#include "pwm.h"


void init_pwm(void) {
	
	// unmask TC7 in MCLK to enable clock to user interface
	MCLK->APBDMASK.reg |= MCLK_APBDMASK_TC7;
	
	// connect GLCK with TC7 module
	GCLK->PCHCTRL[TC7_GCLK_ID].reg = GCLK_PCHCTRL_GEN_GCLK2 | (1 << GCLK_PCHCTRL_CHEN_Pos); 
	
	// do a software reset of the module (write-synchronized)
	TC7->COUNT16.CTRLA.reg = TC_CTRLA_SWRST;
	while (TC7->COUNT16.SYNCBUSY.reg & TC_SYNCBUSY_SWRST);
	
	// set the modes
	TC7->COUNT16.CTRLA.reg = TC_CTRLA_MODE(TC_CTRLA_MODE_COUNT16_Val);
	TC7->COUNT16.WAVE.reg = TC_WAVE_WAVEGEN_NPWM_Val;
	
	// set the duty cycles for each output
	TC7->COUNT16.CC[0].reg = 32767;
	while (TC7->COUNT16.SYNCBUSY.reg & TC_SYNCBUSY_CC0);
	TC7->COUNT16.CC[1].reg = 10000;
	while (TC7->COUNT16.SYNCBUSY.reg & TC_SYNCBUSY_CC1);
	
	// enable the PWM module
	TC7->COUNT16.CTRLA.reg |= TC_CTRLA_ENABLE;
	while (TC7->COUNT16.SYNCBUSY.reg & TC_SYNCBUSY_ENABLE);
		
}