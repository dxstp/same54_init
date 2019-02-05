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
#include "dac.h"

void DAC_init(void) {
	MCLK->APBDMASK.bit.DAC_ = 1;
	printf("DAC     -- unmask DAC to enable interface on APBD.\r\n");
	
	GCLK->PCHCTRL[DAC_GCLK_ID].bit.GEN = GCLK_PCHCTRL_GEN_GCLK3_Val;
	GCLK->PCHCTRL[DAC_GCLK_ID].bit.CHEN = 1;
	while(!(GCLK->PCHCTRL[DAC_GCLK_ID].bit.CHEN));
	printf("DAC     -- connect GLCK3 to DAC.\r\n");
	
	DAC->CTRLA.bit.SWRST = 1;
	while(DAC->SYNCBUSY.bit.SWRST);
	while(DAC->CTRLA.bit.SWRST);
	printf("DAC     -- issue a software reset.\r\n");
	
	DAC->CTRLB.bit.REFSEL = DAC_CTRLB_REFSEL_INTREF_Val;
	DAC->DACCTRL[0].bit.CCTRL = DAC_DACCTRL_CCTRL_CC12M_Val;
	DAC->DACCTRL[0].bit.ENABLE = 1;
	DAC->DACCTRL[0].bit.REFRESH = 1;
	DAC->DACCTRL[0].bit.RUNSTDBY = 1;
	printf("DAC     -- select internal reference, current control to 1MBps mode.\r\n");
	printf("DAC     -- Enable DAC0 with auto refresh every 30us.\r\n");
	
	DAC->CTRLA.bit.ENABLE = 1;
	while(DAC->SYNCBUSY.bit.ENABLE);
	printf("DAC     -- Enable DAC controller.\r\n");
}