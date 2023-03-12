/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  segments_config.h
 *       Module:  segments
 *
 *  Description:  segments HW registers definitions
 *
 *********************************************************************************************************************/
#ifndef SEGMENTS_CONFIG_H
#define SEGMENTS_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define NUM_OF_SEGMENTS 4
#define SEGMENT1_EN_PORT DIO_PORTB
#define SEGMENT1_EN_PIN DIO_PIN6

#define SEGMENT2_EN_PORT DIO_PORTB
#define SEGMENT2_EN_PIN DIO_PIN5

#define SEGMENT3_EN_PORT DIO_PORTA
#define SEGMENT3_EN_PIN DIO_PIN2

#define SEGMENT4_EN_PORT DIO_PORTA
#define SEGMENT4_EN_PIN DIO_PIN3

#define SEGMENT_DATA_PORT DIO_PORTB
#define SEGMENT_DATA_PIN1 DIO_PIN0
#define SEGMENT_DATA_PIN2 DIO_PIN3
#define SEGMENT_DATA_PIN3 DIO_PIN2
#define SEGMENT_DATA_PIN4 DIO_PIN4


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* SEGMENTS_CONFIG_H */

/**********************************************************************************************************************
 *  END OF FILE: segments_config.h
 *********************************************************************************************************************/
