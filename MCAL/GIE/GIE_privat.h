/*
 * GIE_privat.h
 *
 *  Created on: Feb 25, 2023
 *      Author: katbo
 */

#ifndef MCAL_GIE_GIE_PRIVAT_H_
#define MCAL_GIE_GIE_PRIVAT_H_

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of SREG	   		*/
/**			   Register	is  0X5F						   		*/
/****************************************************************/

#define SREG		* ( ( volatile u8 * ) ( 0X5F ) )

#endif /* MCAL_GIE_GIE_PRIVAT_H_ */
