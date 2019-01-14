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
#include <stdint.h>
#include <stdio.h>
#include "rtc.h"

/** 
 * init the RTC module to generate an interrupt every 1s.
 */
void RTC_init(void) {

	OSC32KCTRL->RTCCTRL.reg = OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K;
	//printf("OSC32K  -- select internal 32kHz oscillator as source.\r\n");
	
	RTC->MODE0.CTRLA.reg = RTC_MODE0_CTRLA_SWRST;
	while(RTC->MODE0.SYNCBUSY.bit.SWRST);
	while(RTC->MODE0.CTRLA.bit.SWRST);
	//printf("RTC     -- software reset.\r\n");
	
	RTC->MODE0.CTRLA.reg = 
		  RTC_MODE0_CTRLA_COUNTSYNC
		| RTC_MODE0_CTRLA_PRESCALER_DIV1
		| RTC_MODE0_CTRLA_MATCHCLR;
	while(RTC->MODE0.SYNCBUSY.bit.COUNTSYNC);
	//printf("RTC     -- enable read synchronization for count register.\r\n");
	//printf("RTC     -- set divider to 1.\r\n");
	//printf("RTC     -- enable clear on match.\r\n");
	
	RTC->MODE0.COMP[0].reg = 3276;
	//printf("RTC     -- set compare value to 32768.\r\n");
	
	
	
	RTC->MODE0.CTRLA.reg |= RTC_MODE0_CTRLA_ENABLE;
	while(RTC->MODE0.SYNCBUSY.bit.ENABLE);
	//printf("RTC     -- enable RTC.\r\n");
		
	//RTC->MODE0.INTENSET.bit.CMP0 = 1;
	//printf("RTC     -- enable interrupt for CMP0.\r\n");
}