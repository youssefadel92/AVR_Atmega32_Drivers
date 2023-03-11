/*
 * SPI_priv.h
 *
 *  Created on: Mar 4, 2023
 *      Author: katbo
 */

#ifndef MCAL_SPI_SPI_PRIV_H_
#define MCAL_SPI_SPI_PRIV_H_

#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF  7
#define WCOL  6
#define SPI2X 0

#define ENABLE_INTERRUPT   5
#define DISABLE_INTERRUPT   9

#define LSB_FIRST    8
#define MSB_FIRST    11

#define MASTER  0
#define SLAVE   3

#define LEADING_HIGH   2
#define LEADING_LOW  5


#define LEADING_SAMPLE   0
#define LEADING_SETUP    6



#define MODE_F_4	0
#define MODE_F_16	1
#define MODE_F_64	2
#define MODE_F_128	3





#define SPCR (*((volatile u8 *)0x2D ))
#define SPSR (*((volatile u8 *)0x2E ))
#define SPDR (*((volatile u8 *)0x2F ))


#endif /* MCAL_SPI_SPI_PRIV_H_ */
