/*
 * irqs.c
 *
 * Created: 14.12.2018 10:32:09
 *  Author: M19931
 */ 

#include <sam.h>
#include <stdio.h>
#include "irqs.h"

void init_irqs(void) {
	NVIC_SetPriority(RTC_IRQn, 3);
	printf("IRQ     -- set RTC_IRQ to priority 3.\r\n");
	NVIC_EnableIRQ(RTC_IRQn);
	printf("IRQ     -- enable RTC_IRQ.\r\n");
}