
#include "../../LIB/std_types.h"
#include "../../LIB/bit_math.h"
#include "../../HAL/LED/led.h"
#include "util/delay.h"
#include "TIMR1_int.h"
#include "TIMR1_config.h"
#include "TIMR1_priv.h"

void (*TIMER1_OV_CallBack) (void) ;
void (*TIMER1_CTC_A_CallBack) (void) ;
void (*TIMER1_CTC_B_CallBack) (void) ;

void TIMER1_void_Init(void)
{
	#if(TIMER1_MODE == TIMER1_NORMAL)
		CLEAR_BIT(TCCR1A, 0);
		CLEAR_BIT(TCCR1A, 1);
		CLEAR_BIT(TCCR1A, 4);
		CLEAR_BIT(TCCR1A, 5);
		CLEAR_BIT(TCCR1A, 6);
		CLEAR_BIT(TCCR1A, 7);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	
	#elif(TIMER1_MODE == TIMER1_CTC)
		CLEAR_BIT(TCCR1A, 0);
		CLEAR_BIT(TCCR1A, 1);
		SET_BIT(TCCR1B, 3);
		CLEAR_BIT(TCCR1B, 4);
	#elif(TIMER1_MODE == TIMER1_FAST_PWM_10BIT )
		SET_BIT(TCCR1A, 0);
		SET_BIT(TCCR1A, 1);
		SET_BIT(TCCR1B, 3);
		CLEAR_BIT(TCCR1B, 4);
	#elif(TIMER1_MODE == TIMER1_FAST_PWM_OCR1A )
		SET_BIT(TCCR1A, 0);
		SET_BIT(TCCR1A, 1);
		SET_BIT(TCCR1B, 3);
		SET_BIT(TCCR1B, 4);
		
	#elif(TIMER1_MODE == TIMER1_PHASE_PWM )
		SET_BIT(TCCR1A, 0);
		SET_BIT(TCCR1A, 1);
		CLEAR_BIT(TCCR1B, 3);
		CLEAR_BIT(TCCR1B, 4);
		
	#endif
	
	#if(TIMER1_PRESCALER == TIMER1_DIV_BY_1)
		SET_BIT(TCCR1B , 0);
		CLEAR_BIT(TCCR1B , 1);
		CLEAR_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_8)
		CLEAR_BIT(TCCR1B , 0);
		SET_BIT(TCCR1B , 1);
		CLEAR_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_64 )
		SET_BIT(TCCR1B , 0);
		SET_BIT(TCCR1B , 1);
		CLEAR_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_256 )
		CLEAR_BIT(TCCR1B , 0);
		CLEAR_BIT(TCCR1B , 1);
		SET_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_DIV_BY_1024 )
		SET_BIT(TCCR1B , 0);
		CLEAR_BIT(TCCR1B , 1);
		SET_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_EXT_FALLING )
		CLEAR_BIT(TCCR1B , 0);
		SET_BIT(TCCR1B , 1);
		SET_BIT(TCCR1B , 2);
	#elif(TIMER1_PRESCALER == TIMER1_EXT_RISING )
		SET_BIT(TCCR1B , 0);
		SET_BIT(TCCR1B , 1);
		SET_BIT(TCCR1B , 2);
	#endif
	
	#if(TIMER1_COM_EVENT == TIMER1_NO_ACTION)
		CLEAR_BIT(TCCR1A , 4);
		CLEAR_BIT(TCCR1A , 5);
		CLEAR_BIT(TCCR1A , 6);
		CLEAR_BIT(TCCR1A , 7);
	#elif(TIMER1_COM_EVENT == TIMER1_TOGGLE)
		#if(TIMER1_CTC_CHANNEL==TIMER1_CHANNEL_A)
			SET_BIT(TCCR1A , 6);
			CLEAR_BIT(TCCR1A , 7);
		#elif(TIMER1_CTC_CHANNEL==TIMER1_CHANNEL_B)
			SET_BIT(TCCR1A , 4);
			CLEAR_BIT(TCCR1A , 5);
		#endif
	#elif(TIMER1_COM_EVENT == TIMER1_CLEAR )
		#if(TIMER1_CTC_CHANNEL==TIMER1_CHANNEL_A)
			CLEAR_BIT(TCCR1A , 6);
			SET_BIT(TCCR1A , 7);
		#elif(TIMER1_CTC_CHANNEL==TIMER1_CHANNEL_B)
			CLEAR_BIT(TCCR1A , 4);
			SET_BIT(TCCR1A , 5);
		#endif
	#elif(TIMER1_COM_EVENT == TIMER1_SET )
		#if(TIMER1_CTC_CHANNEL==TIMER1_CHANNEL_A)
			SET_BIT(TCCR1A , 6);
			SET_BIT(TCCR1A , 7);
		#elif(TIMER1_CTC_CHANNEL==TIMER1_CHANNEL_B)
			SET_BIT(TCCR1A , 4);
			SET_BIT(TCCR1A , 5);
		#endif
	#endif
	/*Disable Interrupts*/
	CLEAR_BIT(TIMSK , 2);
	CLEAR_BIT(TIMSK , 3);
	CLEAR_BIT(TIMSK , 4);
	CLEAR_BIT(TIMSK , 5);
	/*CLEAR FLAGS*/
	SET_BIT(TIFR , 2);
	SET_BIT(TIFR , 3);
	SET_BIT(TIFR , 4);
	SET_BIT(TIFR , 5);
	/*Clear register*/
	TCNT1 = 0 ;
	OCR1A = 0 ;
	OCR1B = 0 ;
	
	
}

void TIMER1_void_SetTimerReg(u16 Copy_uint8Val)
{
	TCNT1 = Copy_uint8Val ;
}

void TIMER1_void_SetCompare_A_Val(u16 Copy_uint8Val)
{
	OCR1A = Copy_uint8Val ;
}

void TIMER1_void_SetCompare_B_Val(u16 Copy_uint8Val)
{
	OCR1B = Copy_uint8Val ;
}

void TIMER1_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 2);
}

void TIMER1_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 2);
}

void TIMER1_void_EnableCTC_A_Int(void)
{
	SET_BIT(TIMSK , 4);
}

void TIMER1_void_DisableCTC_A_Int(void)
{
	CLEAR_BIT(TIMSK , 4);
}
void TIMER1_void_EnableCTC_B_Int(void)
{
	SET_BIT(TIMSK , 3);
}

void TIMER1_void_DisableCTC_B_Int(void)
{
	CLEAR_BIT(TIMSK , 3);
}

void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER1_OV_CallBack = Copy_ptr ;
}

void TIMER1_void_SetCTC_A_CallBack(void (*Copy_ptr) (void) )
{
	TIMER1_CTC_A_CallBack = Copy_ptr ;
}
void TIMER1_void_SetCTC_B_CallBack(void (*Copy_ptr) (void) )
{
	TIMER1_CTC_B_CallBack = Copy_ptr ;
}

void __vector_9(void) __attribute__((signal , used));
void __vector_9(void)
{
	TIMER1_OV_CallBack();
}

void __vector_7(void) __attribute__((signal , used));
void __vector_7(void)
{
	TIMER1_CTC_A_CallBack();
}
void __vector_8(void) __attribute__((signal , used));
void __vector_8(void)
{
	TIMER1_CTC_B_CallBack();
}
