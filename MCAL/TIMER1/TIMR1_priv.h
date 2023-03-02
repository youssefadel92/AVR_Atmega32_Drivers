
#ifndef _TIMER1_PRIV
#define _TIMER1_PRIV

#define TIMSK	(*(volatile u8 * )0x59)
#define OCR1A	(*(volatile u16 * )0x4A)
#define OCR1B   (*(volatile u16 * )0x48)
#define TCCR1A	(*(volatile u8 * )0x4F)
#define TCCR1B	(*(volatile u8 * )0x4E)
#define TCNT1	(*(volatile u16 * )0x4C)
#define TIFR	(*(volatile u8 * )0x58)



#define TIMER1_NORMAL 			1
#define TIMER1_CTC 				2
#define TIMER1_FAST_PWM_10BIT	3
#define TIMER1_PHASE_PWM 		4
#define TIMER1_FAST_PWM_OCR1A 	5


#define TIMER1_DIV_BY_1		1
#define TIMER1_DIV_BY_8		5
#define TIMER1_DIV_BY_64	8
#define TIMER1_DIV_BY_256	10
#define TIMER1_DIV_BY_1024	15
#define TIMER1_EXT_FALLING	16
#define TIMER1_EXT_RISING	17


#define TIMER1_NO_ACTION	100
#define TIMER1_TOGGLE		12
#define TIMER1_SET			20
#define TIMER1_CLEAR		25

#define TIMER1_CHANNEL_A	1
#define TIMER1_CHANNEL_B	2

#endif
