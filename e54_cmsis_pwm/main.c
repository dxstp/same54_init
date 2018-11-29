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

#include <stdint.h>

#include "same54.h"
#include "my_init/oscctrl.h"
#include "my_init/gclk.h"
#include "my_init/dpll.h"
#include "my_init/gpio.h"
#include "my_init/pwm.h"


// this examples is designed for the ATSAM E54 Xplained Pro board.
int main(void)
{
	// if everything is left on default, the controller will start with the
	// internal 48 MHz FDPLL0 oscillator, routed to GLCK0.
	// GLCK0 will provide the clock for MCLK, which clocks the CPU, the bus
	// and the modules connected to the bus.
	// However, some peripherals need a separate asynchronous clock and
	// some interfaces of modules must first be unmasked to be clocked by
	// the synchronous bus clock.
	
	// init an external crystal oscillator to 12 MHz
	init_oscctrl();
	
	// connect GCLK0 to DPLL0 (120 MHz)
	// connect GCLK1 to DPLL1 (200 MHz), divide by 200
	// connect GCLK2 to DPLL1 (200 MHz), divide by 2
	init_gclk();
	
	// init DPLL0 and DPLL1
	// clock input is XOSC1, which will by divided by 4 beforehand
	// maximum clock input frequency is 3 MHz
	init_dpll();
	
	// init the GPIO module to ouput GLCK1
	// and PWM from TC7, WO0 and WO1
	init_gpio();
	
	// init the PWM module to generate two 16-bit PWMs
	init_pwm();
	
	
	/* Replace with your application code */
	while (1) {
		__NOP();
	}
}
