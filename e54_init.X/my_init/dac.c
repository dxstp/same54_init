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
#include "dac.h"

void DAC_init(void) {
	MCLK_REGS->MCLK_APBDMASK = MCLK_APBDMASK_DAC(1);
	printf("DAC     -- unmask DAC to enable interface on APBD.\r\n");
	
	GCLK_REGS->GCLK_PCHCTRL[42] = GCLK_PCHCTRL_GEN_GCLK3 | GCLK_PCHCTRL_CHEN(1);
	while(!(GCLK_REGS->GCLK_PCHCTRL[42] & GCLK_PCHCTRL_CHEN_Msk));
	printf("DAC     -- connect GLCK3 to DAC.\r\n");
	
	DAC_REGS->DAC_CTRLA = DAC_CTRLA_SWRST(1);
	while(DAC_REGS->DAC_SYNCBUSY & DAC_SYNCBUSY_SWRST_Msk);
	while(DAC_REGS->DAC_CTRLA & DAC_CTRLA_SWRST_Msk);
	printf("DAC     -- issue a software reset.\r\n");
	
	DAC_REGS->DAC_CTRLB = DAC_CTRLB_REFSEL_VREFPU;
	DAC_REGS->DAC_DACCTRL[0] = 
            DAC_DACCTRL_CCTRL_CC12M
          | DAC_DACCTRL_ENABLE(1)
          | DAC_DACCTRL_REFRESH(1)
          | DAC_DACCTRL_RUNSTDBY(1);
	printf("DAC     -- select unbuffered external reference.\r\n");
	printf("DAC     -- current control to 1MBps mode.\r\n");
	printf("DAC     -- Enable DAC0 with auto refresh every 30us.\r\n");
	
	DAC_REGS->DAC_CTRLA |= DAC_CTRLA_ENABLE(1);
	while(DAC_REGS->DAC_SYNCBUSY & DAC_SYNCBUSY_ENABLE_Msk);
	printf("DAC     -- Enable DAC controller.\r\n");
	
	DAC_REGS->DAC_DATA[0] = 0x0800;
}