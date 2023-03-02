/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  button_config.h
 *       Module:  button
 *
 *  Description:  button HW registers definitions
 *
 *********************************************************************************************************************/
#ifndef BUTTON_CONFIG_H
#define BUTTON_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/std_types.h"
#include "../../MCAL/DIO/dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define num_of_buttons 4

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct{
	dio_portId_t BUTTON_PORT;
	dio_channelId_t BUTTON_CHANNEL_NUM;
	boolean BUTTON_PULL_UP;
	boolean BUTTON_INTERNAL;
}BUTTON_CONFIG;

extern BUTTON_CONFIG buttons[];

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* BUTTON_CONFIG_H */

/**********************************************************************************************************************
 *  END OF FILE: button_config.h
 *********************************************************************************************************************/
