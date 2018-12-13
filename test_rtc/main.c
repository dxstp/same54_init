#include <atmel_start.h>

int main(void)
{
	
	__NOP();
	
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	__NOP();

	RTC->MODE0.CTRLA.reg = 0;
	
		__NOP();
		
		RTC->MODE0.EVCTRL.reg = RTC_MODE0_EVCTRL_PEREO1;
		
		__NOP();
	/* Replace with your application code */
	while (1) {
		__NOP();
	}
}
