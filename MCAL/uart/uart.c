/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  uart.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "uart.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include "../../HAL/LED/led.h"
#include "avr/interrupt.h"



/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 UART_TX_BUFFER[100];
u8 byte_index=0;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void UART_Init(u16 baudRate)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : baudRate   UART baudrate                                                                     
* \Return value:   : None                                   
*******************************************************************************/
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRL_REG = (u8)baudRate;
	UART_UBRRH_REG = (u8)(baudRate>>8);

	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO) | UART_8_BIT_DATA | UART_EVEN_PARITY;

	SET_BIT(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	*/
	SET_BIT(UART_UCSRB_REG,6); /*	Enable Tx Complete Interrupt	*/
}

/******************************************************************************
* \Syntax          : void UART_TransmitChr(u8 data)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : data   data byte                                                                    
* \Return value:   : None                                   
*******************************************************************************/
void UART_TransmitChr(u8 data)
{

	/*
	* UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	* transmitting a new byte so wait until this flag is set to one
	*/
	while(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)==0);
	/*
	* Put the required data in the UDR register and it also clear the UDRE flag as
	* the UDR register is not empty now
	*/
	UART_UDR_REG = data;
}

/******************************************************************************
* \Syntax          : u8 UART_ReceiveChr(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                    
* \Return value:   : u8     received data byte                                   
*******************************************************************************/
u8 UART_ReceiveChr(void)
{
	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
	while(CHECK_BIT(UART_UCSRA_REG,RXC_BIT_NO)==0){}

	/*
	* Read the received data from the Rx buffer (UDR)
	* The RXC flag will be cleared after read the data
	*/
	return UART_UDR_REG;
}

/******************************************************************************
* \Syntax          : u8 UART_TransmitStr(u8 *str)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : u8 *str
* \Return value:   : void
*******************************************************************************/
void UART_TransmitMessage(u8 *str)
{
	//led_toggle(LED1);
	//_delay_ms(5000);
	//led_toggle(LED1);
	if(byte_index==0)
	{
		u8 i=0;
		while(str[i]!='\0')
		{
			UART_TX_BUFFER[i]= str[i];
			i++;
		}
		UART_TX_BUFFER[i]= '\0';
		if(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)==1){
			UART_UDR_REG = UART_TX_BUFFER[byte_index];
		}
		byte_index++;
	}
	else
	{
	}

}


void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if(UART_TX_BUFFER[byte_index]!='\0'){
		UART_UDR_REG = UART_TX_BUFFER[byte_index];
		byte_index++;
	}
	else
	{
		byte_index=0;
	}

}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
