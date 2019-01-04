// DOM-IGNORE-BEGIN
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
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

#include <sam.h>
#include <stdio.h>
#include "pwm.h"


void pwm_init(void) {
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