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
#include "MCAL/TIMER2/TIMR2_int.h"
#include "HAL/LED/led.h"
#include "HAL/BUTTON/button.h"


void Toggle(void){
	led_toggle(LED0);
	_delay_ms(1000);
}

int main(void){

	led_init();

	TIMER2_void_SetCTCCallBack(Toggle);
	TIMER2_void_SetCompareVal(255);
	TIMER2_void_Init();




	TIMER2_void_EnableCTCInt();
	GIE_voidEnable();

	while(1){

	}

	return 0;
}
