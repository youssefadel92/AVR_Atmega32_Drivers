/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 20 April 2019                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for EXT0		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "EXTI0_Config.h"
#include "EXTI0_int.h"
#include "EXTI0_private.h"


/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/

#define NULL ((void*)0)

typedef void(*pf)(void);
volatile pf INT0_ISR = NULL;
volatile pf INT1_ISR = NULL;
volatile pf INT2_ISR = NULL;





/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT0_voidInit (void)
{
	/*  ( if / else if ) condition for Macros */
	#if EXTI0_SENSE_MODE == IOC
	SET_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);

	#elif EXTI0_SENSE_MODE == RISING
	SET_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);

	#elif EXTI0_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 0);
	SET_BIT(MCUCR , 1);

	#elif EXTI0_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 0);
	CLEAR_BIT(MCUCR , 1);

	#endif
	/* End ( if ) condition for Macros */


/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 6 );
	SET_BIT(GIFR , 6 ) ;
}

/****************************************************************/
/* Description    :  This function used to initialize EXT1      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void EXT1_voidInit (void)
{
	/*  ( if / else if ) condition for Macros */
	#if EXTI1_SENSE_MODE == IOC
	SET_BIT(MCUCR , 2);
	CLEAR_BIT(MCUCR , 3);

	#elif EXTI1_SENSE_MODE == RISING
	SET_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);

	#elif EXTI1_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);

	#elif EXTI1_SENSE_MODE == LOW_LEVEL
	CLEAR_BIT(MCUCR , 2);
	CLEAR_BIT(MCUCR , 3);

	#endif
	/* End ( if ) condition for Macros */


/** disable EXT1 in initialization function  **/
/** like : void EXT1_voidDisable(); 		  */
	CLEAR_BIT( GICR , 7 );
	SET_BIT(GIFR , 7 ) ;
}

/****************************************************************/
/* Description    :  This function used to initialize EXT1      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void EXT2_voidInit (void)
{
	/*  ( if / else if ) condition for Macros */

	#if EXTI2_SENSE_MODE == RISING
	SET_BIT(MCUCSR , 6);

	#elif EXTI2_SENSE_MODE == FALLING
	CLEAR_BIT(MCUCSR , 6);

	#endif
	/* End ( if ) condition for Macros */


/** disable EXT0 in initialization function  **/
/** like : void EXT0_voidDisable(); 		  */
	CLEAR_BIT( GICR , 5 );
	SET_BIT(GIFR , 5 ) ;
}


/****************************************************************/
/* Description    : This function used to Enable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidEnable()
{
	
	SET_BIT( GICR , 6 );
	
}

/****************************************************************/
/* Description    : This function used to Enable EXT1			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidEnable()
{
	SET_BIT( GICR , 7 );
}

/****************************************************************/
/* Description    : This function used to Enable EXT2			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidEnable()
{
	SET_BIT( GICR , 5 );
}


/****************************************************************/
/* Description    : This function used to Disable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT0_voidDisable()
{
	
	CLEAR_BIT( GICR , 6 );
	
}

/****************************************************************/
/* Description    : This function used to Disable EXT1			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidDisable()
{
	CLEAR_BIT( GICR , 7 );
}

/****************************************************************/
/* Description    : This function used to Disable EXT2			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidDisable()
{
	CLEAR_BIT( GICR , 5 );
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

void EXT0_voidCallBack(volatile void (*temp)(void))
{
	if(temp != NULL)
	{
		INT0_ISR = temp;
	}
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

void EXT1_voidCallBack(volatile void (*temp)(void))
{
	if(temp != NULL)
	{
		INT1_ISR = temp;
	}
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

void EXT2_voidCallBack(volatile void (*temp)(void))
{
	if(temp != NULL)
	{
		INT2_ISR = temp;
	}
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
void EXT0_voidSetSignalch(u8 SenseCpy)
{
	if (SenseCpy == IOC){
		SET_BIT(MCUCR , 0);
		CLEAR_BIT(MCUCR , 1);
	}
	else if(SenseCpy == RISING){
		SET_BIT(MCUCR , 0);
		SET_BIT(MCUCR , 1);
	}
	else if(SenseCpy == FALLING){
		CLEAR_BIT(MCUCR , 0);
		SET_BIT(MCUCR , 1);
	}
	else if(SenseCpy == LOW_LEVEL){
		CLEAR_BIT(MCUCR , 0);
		CLEAR_BIT(MCUCR , 1);
	}

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
void EXT1_voidSetSignalch(u8 SenseCpy)
{
	if (SenseCpy == IOC){
		SET_BIT(MCUCR , 2);
		CLEAR_BIT(MCUCR , 3);
	}
	else if(SenseCpy == RISING){
		SET_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
	}
	else if(SenseCpy == FALLING){
		CLEAR_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
	}
	else if(SenseCpy == LOW_LEVEL){
		CLEAR_BIT(MCUCR , 2);
		CLEAR_BIT(MCUCR , 3);
	}
	
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
void EXT2_voidSetSignalch(u8 SenseCpy)
{
	if(SenseCpy == RISING){
		SET_BIT(MCUCSR , 6);
	}
	else if(SenseCpy == FALLING){
		CLEAR_BIT(MCUCSR , 6);
	}
}


void __vector_1(void)
{
	INT0_ISR();
	
}
void __vector_2(void)
{
	INT1_ISR();

}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/
