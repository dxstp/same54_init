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
#include "my_init/dac.h"
#include "utils/print.h"


/** 
 * this examples is designed for the ATSAM E54 Xplained Pro board.
 */
int main(void) {
	// if everything is left on default, the controller will start with the
	// internal 48 MHz FDPLL0 oscillator, routed to GLCK0.
	// GLCK0 will provide the clock for MCLK, which clocks the CPU, the bus
	// and the modules connected to the bus.
	// However, some peripherals need a separate asynchronous clock and
	// some interfaces of modules must first be unmasked to be clocked by
	// the synchronous bus clock.
	
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
	DAC_init();
	
	printf("\r\n-- Finished initialization, starting app.\r\n");
DAC->DATA[0].reg = 0x400;
	while (1) {
		

	}
}

void RTC_Handler(void) {
	RTC->MODE0.INTFLAG.reg = RTC_MODE0_INTFLAG_CMP0;
	NVIC_ClearPendingIRQ(RTC_IRQn);
}