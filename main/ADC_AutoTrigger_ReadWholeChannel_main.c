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
#include "HAL/LED/led.h"
#include "HAL/BUTTON/button.h"
#include "HAL/SEVENSEGMENTS/segments.h"

u16 num = 0;
u8 flag=0;
void ahmed(void){
	led_toggle(LED1);
}
void ahmed2(void){
	led_toggle(LED0);
	_delay_ms(50);  	/* Software debouncing control delay */
}

void ADC_Interrupt(void){
	static u8 counter=0;

	num=ADC_u16ReadBuffer(counter);
	counter++;
	if(counter>7)
	{
		counter=0;
	}

}
int main(void){

	button_init();
	led_init();

	SSD_vidinit();
	GIE_voidEnable();

	ADC_voidCallBack(ADC_Interrupt);
	ADC_voidInit();
	ADC_voidInterrputEnable();


	EXT0_voidInit();
	EXT0_voidEnable();


	while(1){
		SSD_DisplayNum(num);
	}

	return 0;
}
