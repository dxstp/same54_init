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
#include <stdint.h>
#include <stdio.h>
#include "rtc.h"

/** 
 * init the RTC module to generate an interrupt every 1s.
 */
void RTC_init(void) {

	OSC32KCTRL_REGS->OSC32KCTRL_RTCCTRL = OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K;
	printf("OSC32K  -- select internal 32kHz oscillator as source.\r\n");
	
	RTC_REGS->MODE0.RTC_CTRLA = RTC_MODE0_CTRLA_SWRST(1);
	while(RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_SWRST_Msk);
	while(RTC_REGS->MODE0.RTC_CTRLA & RTC_MODE0_CTRLA_SWRST_Msk);
	printf("RTC     -- software reset.\r\n");
	
	RTC_REGS->MODE0.RTC_CTRLA = 
		  RTC_MODE0_CTRLA_COUNTSYNC(1)
		| RTC_MODE0_CTRLA_PRESCALER_DIV1
		| RTC_MODE0_CTRLA_MATCHCLR(1);
	while(RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_COUNTSYNC_Msk);
	printf("RTC     -- enable read synchronization for count register.\r\n");
	printf("RTC     -- set divider to 1.\r\n");
	printf("RTC     -- enable clear on match.\r\n");
	
	RTC_REGS->MODE0.RTC_EVCTRL = RTC_MODE0_EVCTRL_CMPEO0(1);
	printf("RTC     -- enable event CMP0, will generate event on match.\r\n");
	
	RTC_REGS->MODE0.RTC_COMP[0] = 32768;
	printf("RTC     -- set compare value to 32768.\r\n");
		
	RTC_REGS->MODE0.RTC_CTRLA |= RTC_MODE0_CTRLA_ENABLE(1);
	while(RTC_REGS->MODE0.RTC_SYNCBUSY & RTC_MODE0_SYNCBUSY_ENABLE_Msk);
	printf("RTC     -- enable RTC.\r\n");
}