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
#include "evsys.h"

void EVSYS_init(void) {
	MCLK->APBBMASK.reg |= MCLK_APBBMASK_EVSYS;
	
	GCLK->PCHCTRL[EVSYS_GCLK_ID_0].reg = GCLK_PCHCTRL_GEN_GCLK0 | (1 << GCLK_PCHCTRL_CHEN_Pos);
	
	EVSYS->CTRLA.reg = EVSYS_CTRLA_SWRST;
	
	EVSYS->USER[57].reg = 0x01; // channel 0: ADC1 start
	
	EVSYS->Channel[0].CHANNEL.reg =
		  EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT
		| EVSYS_CHANNEL_ONDEMAND
		| EVSYS_CHANNEL_RUNSTDBY
		| EVSYS_CHANNEL_PATH_ASYNCHRONOUS
		| EVSYS_CHANNEL_EVGEN(0x0c); // RTC COMP0
	
}