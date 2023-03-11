/*
 * SPI_prg.c
 *
 *  Created on: Mar 4, 2023
 *      Author: katbo
 */


#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "../DIO/dio.h"
#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_config.h"
#include "../../HAL/LED/led.h"

#if INTERRUPT_MODE == ENABLE_INTERRUPT

void (*CallBack) (void);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) )
{
	CallBack = PtrToFunc ;
}

void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{
	CallBack();
}

void SPI_voidSendDataISR(u8 Copy_Data)
{
	SPDR = Copy_Data ;
}

u8 SPI_u8ReadDataISR(void)
{
	return SPDR ;
}


#elif INTERRUPT_MODE == DISABLE_INTERRUPT
u8 SPI_u8Transfer(u8 Copy_Data)
{
	SPDR = Copy_Data ;
	while(CHECK_BIT(SPSR , SPIF) == 0);
	return SPDR ;
}
#endif

#if MASTER_SLAVE_MODE == MASTER
void SPI_voidMasterInit(void)
{
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN4, OUTPUT);
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN5, OUTPUT);
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN6, INPUT);
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN7, OUTPUT);

	#if INTERRUPT_MODE == ENABLE_INTERRUPT
	SET_BIT(SPCR , SPIE);
	#elif INTERRUPT_MODE == DISABLE_INTERRUPT
	CLEAR_BIT(SPCR , SPIE);
	#endif
	SET_BIT(SPCR , MSTR);
	#if DATA_ORDER == MSB_FIRST
	CLEAR_BIT(SPCR , DORD);
	#elif DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR , DORD);
	#endif
	#if CLOCK_POLARITY == LEADING_HIGH
	CLEAR_BIT(SPCR , CPOL);
	#elif CLOCK_POLARITY == LEADING_LOW
	SET_BIT(SPCR , CPOL);
	#endif
	#if CLOCK_PHASE == LEADING_SAMPLE
	CLEAR_BIT(SPCR , CPHA);
	#elif CLOCK_PHASE == ONE
	SET_BIT(SPCR , CPHA);
	#endif

	#if SPI_FREQUENCY == MODE_F_4
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	CLEAR_BIT(SPSR , SPI2X);
	#elif SPI_FREQUENCY == MODE_F_16
	SET_BIT(SPCR , SPR0);
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPSR , SPI2X);
	#elif SPI_FREQUENCY == MODE_F_64
	CLEAR_BIT(SPCR , SPR0);
	SET_BIT(SPCR , SPR1);
	CLEAR_BIT(SPSR , SPI2X);
	#elif SPI_FREQUENCY == MODE_F_128
	SET_BIT(SPCR , SPR0);
	SET_BIT(SPCR , SPR1);
	CLEAR_BIT(SPSR , SPI2X);
	#endif


	SET_BIT(SPCR , SPE);
}

#elif MASTER_SLAVE_MODE == SLAVE

void SPI_voidSlaveInit(void)
{
	SET_BIT(SPCR , SPE);
	#if INTERRUPT_MODE == ENABLE_INTERRUPT
	SET_BIT(SPCR , SPIE);
	#elif INTERRUPT_MODE == DISABLE_INTERRUPT
	CLEAR_BIT(SPCR , SPIE);
	#endif

	CLEAR_BIT(SPCR , MSTR);
	#if DATA_ORDER == MSB_FIRST
	CLEAR_BIT(SPCR , DORD);
	#elif DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR , DORD);
	#endif
	#if CLOCK_POLARITY == LEADING_HIGH
	CLEAR_BIT(SPCR , CPOL);
	#elif CLOCK_POLARITY == LEADING_LOW
	SET_BIT(SPCR , CPOL);
	#endif
	#if CLOCK_PHASE == LEADING_SAMPLE
	CLEAR_BIT(SPCR , CPHA);
	#elif CLOCK_PHASE == ONE
	SET_BIT(SPCR , CPHA);
	#endif

}
#endif
