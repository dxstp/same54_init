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
#include "ccl.h"


/**
 * init CLC
 * to invert SERCOM2 RX/TX signal
 */
void CCL_init(void) {

	MCLK_REGS->MCLK_APBCMASK |= MCLK_APBCMASK_CCL(1);
	printf("CCL     -- unmask CCL to enable interface on APBC.\r\n");
	
	GCLK_REGS->GCLK_PCHCTRL[33] = GCLK_PCHCTRL_GEN_GCLK3 | GCLK_PCHCTRL_CHEN(1);
	printf("CCL     -- connect GCLK3 to CCL.\r\n");
    
	CCL_REGS->CCL_SEQCTRL[0] = CCL_SEQCTRL_SEQSEL(0);
	printf("CCL     -- configure input of LUT[0], IN[0] is IO.\r\n");
    
    CCL_REGS->CCL_LUTCTRL[0] =
            CCL_LUTCTRL_INSEL0_IO
          | CCL_LUTCTRL_INSEL2_MASK
          | CCL_LUTCTRL_LUTEI(0)
          | CCL_LUTCTRL_LUTEO(0)
          | CCL_LUTCTRL_EDGESEL(0)
          | CCL_LUTCTRL_FILTSEL(0)
          | CCL_LUTCTRL_TRUTH(0x01)
          | CCL_LUTCTRL_ENABLE(1);
	printf("CCL     -- configure and enable LUT[0], inverting input.\r\n");
    
	CCL_REGS->CCL_SEQCTRL[1] = CCL_SEQCTRL_SEQSEL_DISABLE;
	printf("CCL     -- configure input of LUT[0], IN[0] is SERCOM2, Pad 0.\r\n");
    
    CCL_REGS->CCL_LUTCTRL[2] =
            CCL_LUTCTRL_INSEL0_SERCOM
          | CCL_LUTCTRL_INSEL1_MASK
          | CCL_LUTCTRL_INSEL2_MASK
          | CCL_LUTCTRL_LUTEI(0)
          | CCL_LUTCTRL_LUTEO(0)
          | CCL_LUTCTRL_EDGESEL(0)
          | CCL_LUTCTRL_FILTSEL(0)
          | CCL_LUTCTRL_TRUTH(0x01)
          | CCL_LUTCTRL_ENABLE(1);
	printf("CCL     -- configure and enable LUT[0], inverting input.\r\n");
	
	CCL_REGS->CCL_CTRL= CCL_CTRL_ENABLE(1);
	printf("CCL     -- enable CCL.\r\n");
}