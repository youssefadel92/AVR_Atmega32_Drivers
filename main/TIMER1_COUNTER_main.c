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
//#include "HAL/SEVENSEGMENTS/segments.h"

u16 num = 0;


void ahmed(void){
	led_toggle(LED1);
}
void ahmed2(void){

	led_toggle(LED0);
	//_delay_ms(1000);
}

void ADC_Interrupt(void){
/*	static u8 counter=0;

	num=ADC_u16InterruptRead(counter);
	counter++;
	if(counter>7)
	{
		counter=0;
	}
	else{
		ADC_voidStartConversion();
	}


*/
	num=ADC_u16ReadBuffer(0);
	//ADC_voidStartConversion();
}
int main(void){

	//button_init();

	/*
	 * Application to simulate 15khz pwm
	 * with 50% duty cycle
	 */
	led_init();

	TIMER1_void_SetCTC_A_CallBack(ahmed);
	//TIMER1_void_SetCTC_B_CallBack(ahmed2);


	TIMER1_void_Init();
	TIMER1_void_SetCompare_A_Val(4); // make an interrupt if buttons clicked 5 times == 4
	// because we need another click to reset counter and make the intterupt
	//TIMER1_void_SetCompare_B_Val(7810);


	TIMER1_void_EnableCTC_A_Int();
	//TIMER1_void_EnableCTC_B_Int();
	GIE_voidEnable();

	/*ADC_voidCallBack(ADC_Interrupt);
	ADC_voidInit();
	ADC_voidInterrputEnable();




	EXT0_voidCallBack(ahmed);
	EXT1_voidCallBack(ahmed2);

	EXT0_voidInit();
	EXT0_voidEnable();

	//EXT1_voidInit();
	//EXT1_voidEnable();
	ADC_voidStartConversion();


*/
	while(1){
		//SSD_DisplayNum(num);
	}

	return 0;
}
