/*
 * main.c
 *
 *  Created on: Feb 26, 2023
 *      Author: katbo
 */



/*
 * main.c
 *
 *  Created on: Feb 24, 2023
 *      Author: katbo
 */
#define F_CPU	16000000UL

#include "MCAL/DIO/dio.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/EXTI/EXTI0_int.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/TIMER/TIMR0_int.h"
#include "MCAL/TIMER2/TIMR2_int.h"
#include "MCAL/TIMER1/TIMR1_int.h"
#include "HAL/LED/led.h"
#include "HAL/BUTTON/button.h"


int main(void){

	led_init();
	button_init();
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN3, OUTPUT);


	TIMER0_void_Init();
	TIMER0_void_STOPCLK();


	while(1){
		if(button_get_status(BUTTON0)==PRESSED){
			while(button_get_status(BUTTON0)==PRESSED){
				TIMER0_void_SetCompareVal(30);
				TIMER0_void_STARTCLK();
			}
		}
		else if(button_get_status(BUTTON1)==PRESSED){
			while(button_get_status(BUTTON1)==PRESSED){
				TIMER0_void_SetCompareVal(100);
				TIMER0_void_STARTCLK();
			}
		}
		TIMER0_void_STOPCLK();
	}
	return 0;
}
