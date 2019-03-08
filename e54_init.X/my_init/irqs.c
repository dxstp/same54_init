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
#include "irqs.h"

void IRQ_init(void) {
	NVIC_SetPriority(RTC_IRQn, 3);
	printf("IRQ     -- set RTC_IRQ to priority 3.\r\n");
	NVIC_EnableIRQ(RTC_IRQn);
	printf("IRQ     -- enable RTC_IRQ.\r\n");
	
	NVIC_SetPriority(ADC1_OTHER_IRQn, 3);
	printf("IRQ     -- set ADC1_0_IRQ to priority 3.\r\n");
	NVIC_EnableIRQ(ADC1_OTHER_IRQn);
	printf("IRQ     -- enable ADC1_0_IRQ.\r\n");
	
	NVIC_SetPriority(ADC1_RESRDY_IRQn, 3);
	printf("IRQ     -- set ADC1_1_IRQ to priority 3.\r\n");
	NVIC_EnableIRQ(ADC1_RESRDY_IRQn);
	printf("IRQ     -- enable ADC1_1_IRQ.\r\n");
	
	NVIC_SetPriority(AC_IRQn, 3);
	printf("IRQ     -- set AC_IRQ to priority 3.\r\n");
	NVIC_EnableIRQ(AC_IRQn);
	printf("IRQ     -- enable AC_IRQ.\r\n");
}
