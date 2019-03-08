// DOM-IGNORE-BEGIN
/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. 
    
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

#include <xc.h>
#include <stdio.h>
#include "pwm.h"

/** 
 * init the PWM module to generate two 16-bit PWMs
 */
void PWM_init(void) {
	MCLK_REGS->MCLK_APBDMASK |= MCLK_APBDMASK_TC7(1);
	printf("PWM     -- unmask TC7 to enable interface on APBD.\r\n");

	GCLK_REGS->GCLK_PCHCTRL[39] = GCLK_PCHCTRL_GEN_GCLK2 | GCLK_PCHCTRL_CHEN(1);
	printf("PWM     -- connect GLCK2 to TC7.\r\n");
	
	// do a software reset of the module (write-synchronized)
	TC7_REGS->COUNT16.TC_CTRLA = TC_CTRLA_SWRST(1);
	while (TC7_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk);
	printf("PWM     -- issue a software reset.\r\n");
	
	TC7_REGS->COUNT16.TC_CTRLA = TC_CTRLA_MODE(TC_CTRLA_MODE_COUNT16_Val);
	TC7_REGS->COUNT16.TC_WAVE = TC_WAVE_WAVEGEN_NPWM_Val;
	printf("PWM     -- set mode to normal PWM in 16-bit counter mode.\r\n");
	
	TC7_REGS->COUNT16.TC_CC[0] = 32767;
	while (TC7_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_CC0_Msk);
	TC7_REGS->COUNT16.TC_CC[1] = 10000;
	while (TC7_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_CC1_Msk);
	printf("PWM     -- set initial duty cycles for CC0 and CC1.\r\n");
	
	TC7_REGS->COUNT16.TC_CTRLA |= TC_CTRLA_ENABLE(1);
	while (TC7_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk);
	printf("PWM     -- enable TC7 module.\r\n");
}