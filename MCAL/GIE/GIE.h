/*
 * GIE.h
 *
 *  Created on: Feb 25, 2023
 *      Author: katbo
 */

#ifndef MCAL_GIE_GIE_H_
#define MCAL_GIE_GIE_H_

/*****************************************************************/
/* Description    : This function used to Enable GIE			 */
/*																 */
/*					Inputs : void					  			 */
/*					Return : void		 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt  */
/*     				 initialized 							     */
/*****************************************************************/

void GIE_voidEnable();

/*****************************************************************/
/* Description    : This function used to Disable GIE			 */
/*																 */
/*					Inputs : void					  			 */
/*					Return : void		 					     */
/*****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt  */
/*     				 initialized 							     */
/*****************************************************************/

void GIE_voidDisable();

#endif /* MCAL_GIE_GIE_H_ */
