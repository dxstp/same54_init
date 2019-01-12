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
	
	MCLK->APBDMASK.reg |= MCLK_APBDMASK_ADC1;
	GCLK->PCHCTRL[GCLK_PCHCTRL_GEN_GCLK0];
	
	Adc->CTRLA.reg = ADC_CTRLA_SWRST;
	while(Adc->SYNCBUSY.reg & ADC_SYNCBUSY_SWRST);
	
	Adc->CTRLA.reg =
		  ADC_CTRLA_ONDEMAND
		| ADC_CTRLA_PRESCALER_DIV2
		| ADC_CTRLA_RUNSTDBY;
	
	Adc->CTRLB.reg = 
		  ADC_CTRLB_WINSS
		| ADC_CTRLB_WINMODE_MODE1
		| ADC_CTRLB_RESSEL_8BIT;
	while(Adc->SYNCBUSY.reg & ADC_SYNCBUSY_CTRLB);
		
	Adc->INPUTCTRL.reg = 
		  ADC_INPUTCTRL_MUXNEG_GND
		| ADC_INPUTCTRL_MUXPOS_AIN6;
	while(Adc->SYNCBUSY.reg & ADC_SYNCBUSY_INPUTCTRL);
	
	Adc->REFCTRL.reg = ADC_REFCTRL_REFSEL_INTREF;
	while(Adc->SYNCBUSY.reg & ADC_SYNCBUSY_REFCTRL);
	
	Adc->WINLT.reg = 127;
	while(Adc->SYNCBUSY.reg & ADC_SYNCBUSY_WINLT);
	
	Adc->CALIB.reg =
		  ADC_CALIB_BIASCOMP((ADC1_FUSES_BIASCOMP_ADDR & ADC1_FUSES_BIASCOMP_Msk) >> ADC1_FUSES_BIASCOMP_Pos)
		| ADC_CALIB_BIASR2R((ADC1_FUSES_BIASR2R_ADDR & ADC1_FUSES_BIASR2R_Msk) >> ADC1_FUSES_BIASR2R_Pos)
		| ADC_CALIB_BIASREFBUF((ADC1_FUSES_BIASREFBUF_ADDR & ADC1_FUSES_BIASR2R_Msk) >> ADC1_FUSES_BIASR2R_Pos);
		
	Adc->EVCTRL.reg = 
		ADC_EVCTRL_STARTEI;
	
	Adc->INTENSET.reg = ADC_INTENSET_WINMON;
	
	Adc->CTRLA.reg |= ADC_CTRLA_ENABLE;	  
}