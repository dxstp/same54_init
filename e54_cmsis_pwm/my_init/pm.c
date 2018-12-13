/*
 * pm.c
 *
 * Created: 13.12.2018 17:23:01
 *  Author: M19931
 */ 

#include <sam.h>
#include <stdio.h>
#include "pm.h"

void init_pm(void) {
	PM->SLEEPCFG.bit.SLEEPMODE = PM_SLEEPCFG_SLEEPMODE_STANDBY;
	printf("PM      -- configured sleep mode to STANDBY.\r\n");
	
	PM->STDBYCFG.bit.RAMCFG = PM_STDBYCFG_RAMCFG_OFF;
	printf("PM      -- configured standby to not retain any system ram.\r\n");
}