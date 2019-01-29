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

/**
 *   https://github.com/dxstp/same54_init
 */

#include <sam.h>
#include <stdio.h>
#include "my_init/oscctrl.h"
#include "my_init/mclk.h"
#include "my_init/gclk.h"
#include "my_init/gpio.h"
#include "my_init/rtc.h"
#include "my_init/supc.h"
#include "my_init/pm.h"
#include "my_init/irqs.h"
#include "my_init/adc.h"
#include "my_init/ac.h"
#include "my_init/evsys.h"
#include "utils/delay.h"


/** 
 * this examples is designed for the ATSAM E54 Xplained Pro board.
 */
int main(void) {
	OSCCTRL_init();
	GCLK_init();
	
	delay_ms(200);
	
	SUPC_init();
	GPIO_init();
	PM_init();
	IRQ_init();
	RTC_init();
	//ADC_init();
	AC_init();
	EVSYS_init();
	
	while (!(PM->INTFLAG.reg == PM_INTFLAG_SLEEPRDY));
	
	while (1) {
		__DSB();
		__WFI();
	}
}

void RTC_Handler(void) {
	RTC->MODE0.INTFLAG.reg = RTC_MODE0_INTFLAG_CMP0;
	NVIC_ClearPendingIRQ(RTC_IRQn);
	while(1);
}

void ADC1_0_Handler(void) {
	ADC1->INTFLAG.reg = ADC_INTFLAG_WINMON;
	NVIC_ClearPendingIRQ(ADC1_0_IRQn);
	//while(1);
	delay_cycles(1000);
}

void ADC1_1_Handler(void) {
	ADC1->INTFLAG.reg = ADC_INTFLAG_RESRDY;
	NVIC_ClearPendingIRQ(ADC1_1_IRQn);
	//while(1);
	delay_cycles(1000);
}

void AC_Handler(void) {
	AC->INTFLAG.reg = AC_INTFLAG_COMP0;
	NVIC_ClearPendingIRQ(AC_IRQn);
	//while(1);
	delay_cycles(1000);
}