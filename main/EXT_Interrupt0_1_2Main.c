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

void toggled1(void){
	led_toggle(LED1);
}
void toggled0(void){
	led_toggle(LED0);
}
void turnoffled0(void){
	led_off(LED0);
}


int main(void){

	button_init();
	led_init();

	SSD_vidinit();
	GIE_voidEnable();

	EXT0_voidCallBack(toggled0);
	EXT1_voidCallBack(toggled1);
	EXT2_voidCallBack(turnoffled0);

	EXT0_voidInit();
	EXT0_voidEnable();

	EXT1_voidInit();
	EXT1_voidEnable();

	EXT2_voidInit();
	EXT2_voidEnable();



	while(1){
		

	}

	return 0;
}
