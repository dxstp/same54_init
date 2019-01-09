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
#include "ccl.h"


/**
 * init CLC
 * to invert SERCOM2 RX/TX signal
 */
void CCL_init(void) {

	MCLK->APBCMASK.reg |= MCLK_APBCMASK_CCL;
	printf("CCL     -- unmask CCL to enable interface on APBC.\r\n");
	
	GCLK->PCHCTRL[CCL_GCLK_ID].reg = GCLK_PCHCTRL_GEN_GCLK3 | GCLK_PCHCTRL_CHEN;
	printf("CCL     -- connect GCLK3 to CCL.\r\n");
	
	CCL->LUTCTRL[0].bit.INSEL0 = CCL_LUTCTRL_INSEL0_IO_Val;
	CCL->LUTCTRL[0].bit.INSEL1 = CCL_LUTCTRL_INSEL2_MASK_Val;
	CCL->LUTCTRL[0].bit.INSEL2 = CCL_LUTCTRL_INSEL2_MASK_Val;
	CCL->LUTCTRL[0].bit.LUTEI = 0;
	CCL->LUTCTRL[0].bit.LUTEO = 0;
	CCL->LUTCTRL[0].bit.EDGESEL = 0;
	CCL->LUTCTRL[0].bit.FILTSEL = CCL_LUTCTRL_FILTSEL_DISABLE_Val;
	CCL->SEQCTRL[0].bit.SEQSEL = CCL_SEQCTRL_SEQSEL_DISABLE_Val;
	printf("CCL     -- configure input of LUT[0], IN[0] is IO.\r\n");
	
	CCL->LUTCTRL[0].bit.TRUTH = 0x01;
	CCL->LUTCTRL[0].bit.ENABLE = 1;
	printf("CCL     -- configure and enable LUT[0], inverting input.\r\n");
	
	CCL->LUTCTRL[2].bit.INSEL0 = CCL_LUTCTRL_INSEL2_SERCOM_Val;
	CCL->LUTCTRL[2].bit.INSEL1 = CCL_LUTCTRL_INSEL2_MASK_Val;
	CCL->LUTCTRL[2].bit.INSEL2 = CCL_LUTCTRL_INSEL2_MASK_Val;
	CCL->LUTCTRL[2].bit.LUTEI = 0;
	CCL->LUTCTRL[2].bit.LUTEO = 0;
	CCL->LUTCTRL[2].bit.EDGESEL = 0;
	CCL->LUTCTRL[2].bit.FILTSEL = CCL_LUTCTRL_FILTSEL_DISABLE_Val;
	CCL->SEQCTRL[1].bit.SEQSEL = CCL_SEQCTRL_SEQSEL_DISABLE_Val;
	printf("CCL     -- configure input of LUT[0], IN[0] is SERCOM2, Pad 0.\r\n");
	
	CCL->LUTCTRL[2].bit.TRUTH = 0x01;
	CCL->LUTCTRL[2].bit.ENABLE = 1;
	printf("CCL     -- configure and enable LUT[0], inverting input.\r\n");
	
	CCL->CTRL.bit.ENABLE = 1;
	printf("CCL     -- enable CCL.\r\n");
}