/*
 * button_config.c
 *
 *  Created on: Feb 18, 2023
 *      Author: katbo
 */

#include "button_config.h"

#include "../../MCAL/DIO/dio.h"
BUTTON_CONFIG buttons[num_of_buttons] = {
	{ DIO_PORTD, DIO_PIN7, 1, 0 },
	{ DIO_PORTD, DIO_PIN6, 1, 0 },
	{ DIO_PORTD, DIO_PIN5, 1, 0 },
	{ DIO_PORTD, DIO_PIN3, 1, 0 }
};
