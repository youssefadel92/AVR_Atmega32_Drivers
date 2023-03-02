#ifndef _TIMER1_INT_H
#define _TIMER1_INT_H


void TIMER1_void_Init(void);

void TIMER1_void_SetTimerReg(u16 Copy_uint8Val);

void TIMER1_void_SetCompare_A_Val(u16 Copy_uint8Val);

void TIMER1_void_SetCompare_B_Val(u16 Copy_uint8Val);

void TIMER1_void_EnableOVInt(void);

void TIMER1_void_DisableOVInt(void);

void TIMER1_void_EnableCTC_A_Int(void);

void TIMER1_void_DisableCTC_A_Int(void);

void TIMER1_void_EnableCTC_B_Int(void);

void TIMER1_void_DisableCTC_B_Int(void);

void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCTC_A_CallBack(void (*Copy_ptr) (void) ) ;
void TIMER1_void_SetCTC_B_CallBack(void (*Copy_ptr) (void) ) ;



#endif
