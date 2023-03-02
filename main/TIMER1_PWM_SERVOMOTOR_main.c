/*
 * main.c
 *
 *  Created on: Mar 2, 2023
 *      Author: katbo
 */


#define F_CPU 8000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>			/* Include AVR std. library file */
#include <stdio.h>			/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"
#include "MCAL/TIMER1/TIMR1_int.h"

int main(void)
{
	DDRD |= (1<<PD4);	/* Make OC1A pin as output */
	TIMER1_void_Init();
	TIMER1_void_SetCompare_A_Val(625);

	while(1)
	{
		TIMER1_void_SetCompare_B_Val(16);		/* Set servo shaft at -90° position */
		_delay_ms(1500);
		TIMER1_void_SetCompare_B_Val(43);	/* Set servo shaft at 0° position */
		_delay_ms(1500);
		TIMER1_void_SetCompare_B_Val(75);	/* Set servo at +90° position */
		_delay_ms(1500);
	}
}
