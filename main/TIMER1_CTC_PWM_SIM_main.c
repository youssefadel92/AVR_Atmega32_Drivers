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
#include "MCAL/TIMER1/TIMR1_int.h"
#include "HAL/LED/led.h"
#include "HAL/BUTTON/button.h"

void ahmed2(void){
	led_toggle(LED0);
	//_delay_ms(1000);
}


int main(void){


	/*
	 * Application to simulate 15khz pwm
	 * with 50% duty cycle
	 */
	led_init();

	TIMER1_void_SetCTC_A_CallBack(ahmed2);
	TIMER1_void_SetCTC_B_CallBack(ahmed2);


	TIMER1_void_Init();
	TIMER1_void_SetCompare_A_Val(15625);
	TIMER1_void_SetCompare_B_Val(7810);


	TIMER1_void_EnableCTC_A_Int();
	TIMER1_void_EnableCTC_B_Int();
	GIE_voidEnable();

	while(1){
		
	}

	return 0;
}
