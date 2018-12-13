/*
 * supc.c
 *
 * Created: 13.12.2018 17:16:47
 *  Author: M19931
 */ 

#include <sam.h>
#include <stdio.h>
#include "supc.h"

void init_supc(void) {
	SUPC->VREG.bit.SEL = 1;
	printf("SUPC    -- activated buck regulator for VDDCORE.\r\n");
}