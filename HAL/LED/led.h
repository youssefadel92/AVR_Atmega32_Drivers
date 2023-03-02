/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  led.h
 *       Module:  led
 *
 *  Description:  led APIs
 *
 *********************************************************************************************************************/
#ifndef LED_H_H
#define LED_H_H
//pc0 1 2
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "led_config.h"
#include "led_types.h"
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/DIO/dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

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
void led_init(void);
void led_on(LED_ID);
void led_off(LED_ID);
void led_toggle(LED_ID);

#endif  /* LED_H_H */

/**********************************************************************************************************************
 *  END OF FILE: led.h
 *********************************************************************************************************************/