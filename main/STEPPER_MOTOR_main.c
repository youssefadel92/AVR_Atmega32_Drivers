/*
 * main.c
 *
 *  Created on: Mar 1, 2023
 *      Author: katbo
 */



#include <avr/io.h>			/* Include AVR std. library file */
#define F_CPU 16000000UL
#include <util/delay.h>		/* Include delay header file */
#include "HAL/STEPPERMOTOR/StepperMotor.h"

#define period 150
int main(void)
{
	Stepper_motor_init();
	Stepper_motor_rotate(0, 20, CLOCKWISE, 12, FULL_STEP);
	_delay_ms(500);
	Stepper_motor_rotate(0, 20, ANTI_CLOCKWISE, 12, FULL_STEP);

	return 0;
}
