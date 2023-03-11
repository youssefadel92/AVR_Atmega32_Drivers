/*
 * main.c
 *
 *  Created on: Mar 3, 2023
 *      Author: katbo
 */

#define F_CPU 16000000UL
#include "avr/io.h"
#include "MCAL/uart/uart.h"
#include "util/delay.h"
#include "HAL/LED/led.h"
#include "MCAL/GIE/GIE.h"

int main (void){
	led_init();
	GIE_voidEnable();
	UART_Init(UART_BAUDRATE_9600);
	UART_TransmitChr('A');
	u8 string[] = "youssef adel";
	UART_TransmitSTRING(string);
	while(1){
		//data=UART_ReceiveChr();
		_delay_ms(1000);
		UART_TransmitChr('A');
		//led_toggle(LED0);
		//_delay_ms(500);
	}


	return 0;
}
