/*
 * main.c
 *
 *  Created on: Mar 4, 2023
 *      Author: katbo
 */

#include "MCAL/SPI/SPI_int.h"
#include "HAL/LED/led.h"
#include "avr/io.h"
#include "util/delay.h"

int main(void){
	led_init();
	SPI_voidMasterInit();
	PORTB &= (0<<4);			/* Make high on SS pin */
	while(1){
		SPI_u8Transfer('a');
		_delay_ms(200);
	}
	return 0;
}
