/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  segments.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "segments.h"
#include "util/delay.h"

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
* \Syntax          : void SSD_vidinit(void)
* \Description     : this service for initialzing seven segments
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void SSD_vidinit(void)
{
	dio_vidConfigChannel(SEGMENT1_EN_PORT, SEGMENT1_EN_PIN, OUTPUT);
	dio_vidConfigChannel(SEGMENT2_EN_PORT, SEGMENT2_EN_PIN, OUTPUT);
	dio_vidConfigChannel(SEGMENT3_EN_PORT, SEGMENT3_EN_PIN, OUTPUT);
	dio_vidConfigChannel(SEGMENT4_EN_PORT, SEGMENT4_EN_PIN, OUTPUT);

	dio_vidConfigChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN1, OUTPUT);
	dio_vidConfigChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN2, OUTPUT);
	dio_vidConfigChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN3, OUTPUT);
	dio_vidConfigChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN4, OUTPUT);

	dio_vidWriteChannel(SEGMENT1_EN_PORT, SEGMENT1_EN_PIN, 0);
	dio_vidWriteChannel(SEGMENT2_EN_PORT, SEGMENT2_EN_PIN, 0);
	dio_vidWriteChannel(SEGMENT3_EN_PORT, SEGMENT3_EN_PIN, 0);
	dio_vidWriteChannel(SEGMENT4_EN_PORT, SEGMENT4_EN_PIN, 0);

	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN1, 0);
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN2, 0);
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN3, 0);
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN4, 0);

}

/******************************************************************************
* \Syntax          : void SSD_DisplayNum(u16 num);
* \Description     : this service for displaying number in seven segments
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : num 	   -> 16 bit storage
* \Return value:   : None
*******************************************************************************/
void SSD_DisplayNum(u16 num)
{
	u8 first_digit=num/100/10;
	u8 second_digit=num/100%10;
	u8 third_digit=num%100/10;
	u8 fourth_digit=num%100%10;


	dio_vidWriteChannel(SEGMENT1_EN_PORT, SEGMENT1_EN_PIN, 1);
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN1, CHECK_BIT(first_digit,0));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN2, CHECK_BIT(first_digit,1));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN3, CHECK_BIT(first_digit,2));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN4, CHECK_BIT(first_digit,3));
	_delay_us(20);
	dio_vidWriteChannel(SEGMENT1_EN_PORT, SEGMENT1_EN_PIN, 0);

	dio_vidWriteChannel(SEGMENT2_EN_PORT, SEGMENT2_EN_PIN, 1);
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN1, CHECK_BIT(second_digit,0));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN2, CHECK_BIT(second_digit,1));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN3, CHECK_BIT(second_digit,2));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN4, CHECK_BIT(second_digit,3));
	_delay_us(20);
	dio_vidWriteChannel(SEGMENT2_EN_PORT, SEGMENT2_EN_PIN, 0);

	dio_vidWriteChannel(SEGMENT3_EN_PORT, SEGMENT3_EN_PIN, 1);
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN1, CHECK_BIT(third_digit,0));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN2, CHECK_BIT(third_digit,1));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN3, CHECK_BIT(third_digit,2));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN4, CHECK_BIT(third_digit,3));
	_delay_us(20);
	dio_vidWriteChannel(SEGMENT3_EN_PORT, SEGMENT3_EN_PIN, 0);

	dio_vidWriteChannel(SEGMENT4_EN_PORT, SEGMENT4_EN_PIN, 1);
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN1, CHECK_BIT(fourth_digit,0));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN2, CHECK_BIT(fourth_digit,1));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN3, CHECK_BIT(fourth_digit,2));
	dio_vidWriteChannel(SEGMENT_DATA_PORT, SEGMENT_DATA_PIN4, CHECK_BIT(fourth_digit,3));
	_delay_us(20);
	dio_vidWriteChannel(SEGMENT4_EN_PORT, SEGMENT4_EN_PIN, 0);
}

/**********************************************************************************************************************
 *  END OF FILE: segments.c
 *********************************************************************************************************************/
