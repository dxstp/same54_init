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
#include "my_init/sercom.h"
#include "my_init/rtc.h"
#include "my_init/supc.h"
#include "my_init/pm.h"
#include "my_init/irqs.h"
#include "my_init/adc.h"
#include "my_init/evsys.h"
#include "utils/print.h"


/** 
 * this examples is designed for the ATSAM E54 Xplained Pro board.
 */
int main(void) {
	//if(RSTC->RCAUSE.reg == RSTC_RCAUSE_BACKUP && RSTC->BKUPEXIT.reg == RSTC_BKUPEXIT_RTC);
	RTC_init();
	SUPC_init();
	GPIO_init();
	PM_init();
	ADC_init();
	EVSYS_init();
	GCLK_init();
	
	while (!(PM->INTFLAG.reg == PM_INTFLAG_SLEEPRDY));
	//__DSB();
	//__WFI();

	while (1) {
	}
}
