/*
 * SPI_int.h
 *
 *  Created on: Mar 4, 2023
 *      Author: katbo
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

#include "../../LIB/std_types.h"
#define DUMMY 0xFF

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

u8 SPI_u8Transfer(u8 Copy_Data);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) );

u8 SPI_u8ReadDataISR(void);

void SPI_voidSendDataISR(u8 Copy_Data);

#endif /* MCAL_SPI_SPI_INT_H_ */
