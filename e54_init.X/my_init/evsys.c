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
#include "evsys.h"

void EVSYS_init(void) {
	MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_EVSYS(1);
	
	GCLK_REGS->GCLK_PCHCTRL[11] = GCLK_PCHCTRL_GEN_GCLK0 | GCLK_PCHCTRL_CHEN(1);
	
	EVSYS_REGS->EVSYS_CTRLA = EVSYS_CTRLA_SWRST(1);
	
	EVSYS_REGS->EVSYS_USER[57] = 0x01; // channel 0: ADC1 start conversion
	EVSYS_REGS->EVSYS_USER[59] = 0x01; // channel 0: AC0 start compare
	
	EVSYS_REGS->CHANNEL[0].EVSYS_CHANNEL =
		  EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT
		| EVSYS_CHANNEL_ONDEMAND(1)
		| EVSYS_CHANNEL_RUNSTDBY(1)
		| EVSYS_CHANNEL_PATH_ASYNCHRONOUS
		| EVSYS_CHANNEL_EVGEN(0x0c); // RTC COMP0
	
}