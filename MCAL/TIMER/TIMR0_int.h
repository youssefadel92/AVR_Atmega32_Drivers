#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H

#define TIMER0_PWM_PORT		DIO_PORTB
#define TIMER0_PWM_PIN		DIO_PIN3

void TIMER0_void_Init(void);

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val);

void TIMER0_void_EnableOVInt(void);

void TIMER0_void_DisableOVInt(void);

void TIMER0_void_EnableCTCInt(void);

void TIMER0_void_DisableCTCInt(void);

void TIMER0_void_STOPCLK(void);

void TIMER0_void_STARTCLK(void);

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;



#endif
