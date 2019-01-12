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
#include "adc.h"

void ADC_init(void) {
	MCLK->APBDMASK.reg |= MCLK_APBDMASK_ADC0;
	printf("ADC     -- unmask ADC to enable interface on APBD.\r\n");
	
	GCLK->PCHCTRL[ADC0_GCLK_ID].reg = GCLK_PCHCTRL_GEN_GCLK3 | GCLK_PCHCTRL_CHEN;
	printf("ADC     -- connect GCLK3 to ADC.\r\n");
	
	ADC0->CTRLA.reg = ADC_CTRLA_SWRST;
	while(ADC0->SYNCBUSY.reg & ADC_SYNCBUSY_SWRST);
	printf("ADC     -- issue a software reset.\r\n");

	ADC0->INPUTCTRL.reg =
	ADC_INPUTCTRL_MUXNEG_GND
	| ADC_INPUTCTRL_MUXPOS_AIN6;
	while(ADC0->SYNCBUSY.reg & ADC_SYNCBUSY_INPUTCTRL);
	printf("ADC     -- select AIN6 as input.\r\n");
		
	ADC0->REFCTRL.reg = ADC_REFCTRL_REFSEL_INTREF;
	while(ADC0->SYNCBUSY.reg & ADC_SYNCBUSY_REFCTRL);
	printf("ADC     -- select internal reference (nom. 1.1V).\r\n");
	
	ADC0->CALIB.reg =
	ADC_CALIB_BIASCOMP((ADC1_FUSES_BIASCOMP_ADDR & ADC1_FUSES_BIASCOMP_Msk) >> ADC1_FUSES_BIASCOMP_Pos)
	| ADC_CALIB_BIASR2R((ADC1_FUSES_BIASR2R_ADDR & ADC1_FUSES_BIASR2R_Msk) >> ADC1_FUSES_BIASR2R_Pos)
	| ADC_CALIB_BIASREFBUF((ADC1_FUSES_BIASREFBUF_ADDR & ADC1_FUSES_BIASR2R_Msk) >> ADC1_FUSES_BIASR2R_Pos);
	printf("ADC     -- select internal reference (nom. 1.1V).\r\n");
	
	ADC0->CTRLA.reg |= ADC_CTRLA_ENABLE;
	printf("ADC     -- enable ADC.\r\n");
}