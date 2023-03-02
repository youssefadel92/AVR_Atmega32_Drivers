/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 2 May 2019	                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/
#include "util/delay.h"

#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "../DIO/dio.h"
#include "ADC_config.h"
#include "ADC_int.h"
#include "ADC_private.h"

u16 result=0;

typedef void(*pf)(void);
volatile pf ADC_ISR = NULL;

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	ADMUX =0;

	dio_vidConfigChannel(DIO_PORTA, DIO_PIN0, INPUT);

	ADCSRA |= (ADC_PRESCALLER);

	ADC_voidAutoTrigger();

	ADMUX |= (VOLTAGE_REFERENCE<<6);

	ADMUX |= (ADJUSTMENT<<5);

	ADC_voidEnable();
}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	SET_BIT( ADCSRA , ADEN );
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{
	SET_BIT( ADCSRA , ADIE );
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	SET_BIT( ADCSRA , ADSC );
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger()
{
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

    SET_BIT( ADCSRA , ADATE );
	

		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	CLEAR_BIT( SFIOR , ADTS0 );
	CLEAR_BIT( SFIOR , ADTS1 );
	CLEAR_BIT( SFIOR , ADTS2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , ADTS0 );
	CLEAR_BIT( SFIOR , ADTS1 );
	CLEAR_BIT( SFIOR , ADTS2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , ADTS0 );
	SET_BIT( SFIOR , ADTS1 );
	CLEAR_BIT( SFIOR , ADTS2 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , ADTS0 );
	SET_BIT( SFIOR , ADTS1 );
	CLEAR_BIT( SFIOR , ADTS2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , ADTS0 );
	CLEAR_BIT( SFIOR , ADTS1 );
	SET_BIT( SFIOR , ADTS2 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , ADTS0 );
	CLEAR_BIT( SFIOR , ADTS1 );
	SET_BIT( SFIOR , ADTS2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , ADTS0 );
	SET_BIT( SFIOR , ADTS1 );
	SET_BIT( SFIOR , ADTS2 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , ADTS0 );
	SET_BIT( SFIOR , ADTS1 );
	SET_BIT( SFIOR , ADTS2 );
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and wait		*/
/*																*/
/*					Inputs : u8 ADC_CHANNEL_NUMBER	  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV(u8 ADC_CHANNEL_NUMBER)
{
	ADMUX = (ADMUX & 0xE0) | (ADC_CHANNEL_NUMBER & 0x07); // clear first 5bits of admux and clear last 5bits of channel num
	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */

	#if ADJUSTMENT == RIGHT_ADJUSTMENT
	return ADC;
	#elif ADJUSTMENT == LEFT_ADJUSTMENT
	return ADC>>6
	#endif			/* Return digital value*/
}

/****************************************************************/
/* Description    : This function used to Read BUFFER ADC		*/
/*																*/
/*					Inputs : u8 ADC_CHANNEL_NUMBER	  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadBuffer(u8 ADC_CHANNEL_NUMBER)
{

	ADMUX = (ADMUX & 0xE0) | (ADC_CHANNEL_NUMBER & 0x07); // clear first 5bits of admux and clear last 5bits of channel num

	#if ADJUSTMENT == RIGHT_ADJUSTMENT
	return ADC;
	#elif ADJUSTMENT == LEFT_ADJUSTMENT
	return ADC>>6
	#endif

}

/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

/****************************************************************/
/* Description    : This function used to Read whole channel ADC */
/*					in busy loop								*/
/*					Inputs : u16 array[]				  		*/
/*					Return : none	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_u16ChannelRead(u16 array[])
{
	array[0]= ADC_u16ReadADCInMV(0);
	array[1]= ADC_u16ReadADCInMV(1);
	array[2]= ADC_u16ReadADCInMV(2);
	array[3]= ADC_u16ReadADCInMV(3);
	array[4]= ADC_u16ReadADCInMV(4);
	array[5]= ADC_u16ReadADCInMV(5);
	array[6]= ADC_u16ReadADCInMV(6);
	array[7]= ADC_u16ReadADCInMV(7);
}

void ADC_voidCallBack(volatile void (*temp)(void))
{
	if(temp != NULL)
	{
		ADC_ISR = temp;
	}


}
void __vector_16(void)
{
	ADC_ISR();
}


/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
