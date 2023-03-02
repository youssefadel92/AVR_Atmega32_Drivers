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
#define F_CPU		16000000UL

#include "MCAL/DIO/dio.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/EXTI/EXTI0_int.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "MCAL/GIE/GIE.h"
#include "MCAL/TIMER/TIMR0_int.h"
#include "HAL/LED/led.h"
#include "HAL/BUTTON/button.h"

int main(void){

	led_init();

	dio_vidWriteChannel(DIO_PORTA, DIO_PIN4, STD_LOW);
	_delay_ms(2000);
	dio_vidWriteChannel(DIO_PORTA, DIO_PIN4, STD_HIGH);


	TIMER0_void_Init();




	GIE_voidEnable();

	dio_vidConfigChannel(DIO_PORTB, DIO_PIN3, OUTPUT);
	while(1){
		for(u8 i=0;i<255;i++){
			TIMER0_void_SetCompareVal(i);
			_delay_ms(10);
		}

	}

	return 0;
}
