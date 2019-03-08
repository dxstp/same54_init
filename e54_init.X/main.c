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

#include <xc.h>
#include <stdio.h>
#include "my_init/oscctrl.h"
#include "my_init/gclk.h"
#include "my_init/dpll.h"
#include "my_init/gpio.h"
#include "my_init/ccl.h"
#include "my_init/pwm.h"
#include "my_init/sercom.h"
#include "my_init/rtc.h"
#include "my_init/supc.h"
#include "my_init/pm.h"
#include "my_init/irqs.h"
#include "my_init/evsys.h"
#include "my_init/dac.h"
#include "my_init/adc.h"
#include "my_init/ac.h"
#include "utils/print.h"
#include "utils/delay.h"


/** 
 * this examples is designed for the ATSAM E54 Xplained Pro board.
 */
int main(void) {
	 OSCCTRL_init();
	 GCLK_init();
	 SERCOM2_init();
	 print_init();
	
	// init the GPIO module to output GLCK1
	// PWM from TC7, WO0 and WO1
	// RX = PB24, TX = PB25 (for Xplained Board)
	 GPIO_init();
	
	// at this point the controller is able to output debug messages
	printf("\r\n-- SAME54 Xplained Pro boot example --\r\n");
	printf("Built "__TIME__" at "__DATE__"\r\n\r\n");
	printf("OSCCTRL -- XOSC1 (12 MHz) running.\r\n");
	printf("GCLK0   -- connected to DPLL0 (120 MHz).\r\n");
	printf("GCLK1   -- connected to DPLL1 (200 MHz).\r\n");
	printf("GCLK2   -- connected to DPLL1 (200 MHz), divider 200, output enabled (PB15).\r\n");
	printf("GCLK3   -- connected to XOSC1 ( 12 MHz).\r\n");
	printf("GCLK4   -- connected to OSCULP32K (32.768 kHz).\r\n");
	printf("GPIO    -- configured PMUX for GCLK1, TC7 WO0 and WO1, UART RX and TX.\r\n");
	printf("UART    -- initialized to 115200 baud, 8N1.\r\n");
	
	CCL_init();
	RTC_init();
	DPLL_init();
	PWM_init();
	SUPC_init();
	PM_init();
	IRQ_init();
	EVSYS_init();
	DAC_init();
	ADC_init();
	AC_init();
	
	
	printf("\r\n-- Finished initialization, starting app.\r\n");
	
	
	__DSB();
	__WFI();
	
	while (1) {
	
	}
}

void RTC_Handler(void) {
	RTC_REGS->MODE0.RTC_INTFLAG |= RTC_MODE0_INTFLAG_CMP0(1);
	NVIC_ClearPendingIRQ(RTC_IRQn);
}

void HardFault_Handler(void) {
	while(1);
}

void ADC1_0_Handler(void) {
	ADC1_REGS->ADC_INTFLAG |= ADC_INTFLAG_WINMON(1);
	NVIC_ClearPendingIRQ(ADC1_OTHER_IRQn);
	//while(1);
	delay_cycles(1000);
}

void ADC1_1_Handler(void) {
	ADC1_REGS->ADC_INTFLAG |= ADC_INTFLAG_RESRDY(1);
	NVIC_ClearPendingIRQ(ADC1_RESRDY_IRQn);
	//while(1);
	delay_cycles(1000);
}

void AC_Handler(void) {
	AC_REGS->AC_INTFLAG = AC_INTFLAG_COMP0(1);
	NVIC_ClearPendingIRQ(AC_IRQn);
	//while(1);
	delay_cycles(1000);
}