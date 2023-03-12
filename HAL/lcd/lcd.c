/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  lcd.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "util/delay.h"
#include "lcd.h"
#include "lcd_config.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : void button_init(void)
* \Description     : this service for initialzing buttons
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void LCD_init(void)
{
	dio_vidConfigChannel(LCD_RS_PORT_ID, LCD_RS_PIN_ID, OUTPUT);
	dio_vidConfigChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, OUTPUT);
	dio_vidConfigChannel(LCD_DATA_PORT_ID,DIO_PIN0, OUTPUT);
	dio_vidConfigChannel(LCD_DATA_PORT_ID,DIO_PIN1, OUTPUT);
	dio_vidConfigChannel(LCD_DATA_PORT_ID,DIO_PIN2, OUTPUT);
	dio_vidConfigChannel(LCD_DATA_PORT_ID,DIO_PIN4, OUTPUT);


	LCD_sendCommand(0x02); // to initialize LCD in 4-bit mode.
	LCD_sendCommand(0x28); //to initialize LCD in 2 lines, 5X7 dots and 4bit mode.
	LCD_sendCommand(0x0E);
	LCD_sendCommand(0x06);

	//LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);	/* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_sendCommand(LCD_CURSOR_ON);	/* Display on cursor off */
	//LCD_sendCommand(LCD_INCREMENT_COMMAND);	/* Increment cursor (shift cursor to right) */
	//LCD_sendCommand(LCD_CLEAR_COMMAND);	/* Clear display screen */

}
void LCD_sendCommand(u8 command)
{
	dio_vidWriteChannel(LCD_RS_PORT_ID, LCD_RS_PIN_ID, STD_LOW);
	_delay_ms(1); /* delay for processing Tas = 50ns */

	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN0, CHECK_BIT((command & 0xF0)>>4,0));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN1, CHECK_BIT((command & 0xF0)>>4,1));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN2, CHECK_BIT((command & 0xF0)>>4,2));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN4, CHECK_BIT((command & 0xF0)>>4,3));




	dio_vidWriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, STD_HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	dio_vidWriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, STD_LOW);
	_delay_ms(1); /* delay for processing Th*/


	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN0, CHECK_BIT(command,0));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN1, CHECK_BIT(command,1));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN2, CHECK_BIT(command,2));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN4, CHECK_BIT(command,3));

	dio_vidWriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, STD_HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	dio_vidWriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, STD_LOW);
	_delay_ms(1); /* delay for processing Th*/
}
void LCD_displayCharacter(u8 character){
	dio_vidWriteChannel(LCD_RS_PORT_ID, LCD_RS_PIN_ID, STD_HIGH);
	_delay_ms(1); /* delay for processing Tas = 50ns */

	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN0, CHECK_BIT((character & 0xF0)>>4,0));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN1, CHECK_BIT((character & 0xF0)>>4,1));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN2, CHECK_BIT((character & 0xF0)>>4,2));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN4, CHECK_BIT((character & 0xF0)>>4,3));




	dio_vidWriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, STD_HIGH);
	_delay_ms(1); /* delay for processing Tdws*/
	dio_vidWriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, STD_LOW);
	_delay_ms(1); /* delay for processing Th*/

	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN0, CHECK_BIT(character,0));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN1, CHECK_BIT(character,1));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN2, CHECK_BIT(character,2));
	dio_vidWriteChannel(LCD_DATA_PORT_ID, DIO_PIN4, CHECK_BIT(character,3));

	dio_vidWriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, STD_HIGH);
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	dio_vidWriteChannel(LCD_E_PORT_ID, LCD_E_PIN_ID, STD_LOW);
	_delay_ms(1); /* delay for processing Th*/
}


/**********************************************************************************************************************
 *  END OF FILE: lcd.c
 *********************************************************************************************************************/
