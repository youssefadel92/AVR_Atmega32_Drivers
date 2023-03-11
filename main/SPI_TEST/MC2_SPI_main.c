/*
 * main.c
 *
 *  Created on: Mar 4, 2023
 *      Author: katbo
 */

#include "MCAL/SPI/SPI_int.h"
#include "MCAL/GIE/GIE.h"
#include "HAL/LED/led.h"
#include "avr/io.h"

void toggle_led(){
	u8 data = SPI_u8ReadDataISR();
	if(data=='a')
	{
		led_toggle(LED0);
	}
}
int main(void){
	led_init();
	led_on(LED0);
	SPI_voidSetCallBack(toggle_led);
	SPI_voidSlaveInit();
	GIE_voidEnable();
	while(1){

	}
	return 0;
}
