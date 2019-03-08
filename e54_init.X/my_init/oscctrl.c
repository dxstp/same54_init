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
#include "oscctrl.h"

/**
 * OSCCTRL: setup XOSC1 with 12 MHz
 * multiplier and current according to table 28-7.
 * if everything is left on default, the controller will start with the
 * internal 48 MHz FDPLL0 oscillator, routed to GLCK0.
 * GLCK0 will provide the clock for MCLK, which clocks the CPU, the bus
 * and the modules connected to the bus.
 * However, some peripherals need a separate asynchronous clock and
 * some interfaces of modules must first be unmasked to be clocked by
 * the synchronous bus clock.
 * 
 * init an external crystal oscillator to 12 MHz
 */
void OSCCTRL_init(void) {
	OSCCTRL_REGS->OSCCTRL_XOSCCTRL[1] =
		  OSCCTRL_XOSCCTRL_IMULT(4)
		| OSCCTRL_XOSCCTRL_IPTAT(3)
		| OSCCTRL_XOSCCTRL_XTALEN(1)
		| OSCCTRL_XOSCCTRL_ENABLE(1);
	
	while(!(OSCCTRL_REGS->OSCCTRL_INTFLAG & OSCCTRL_INTFLAG_XOSCRDY1_Msk));
}