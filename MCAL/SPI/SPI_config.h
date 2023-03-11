/*
 * SPI_config.h
 *
 *  Created on: Mar 4, 2023
 *      Author: katbo
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

/*Enable SPI Interrupt Mode*/
/*
 * ENABLE_INTERRUPT
 * DISABLE_INTERRUPT
 *
 */

#define INTERRUPT_MODE DISABLE_INTERRUPT

/*SPI Data Order*/
/*
 * LSB_FIRST
 * MSB_FIRST
 *
 */

#define DATA_ORDER  MSB_FIRST

/*Master or Slave Select*/
/*
 * MASTER
 * SLAVE
 *
 */

#define MASTER_SLAVE_MODE  MASTER
/*
 * Clock Polarity mode
 * LEADING_HIGH >> leading edge is rising
 * LEADING_LOW >> leading edge is falling
 *
 */
#define CLOCK_POLARITY  LEADING_HIGH


/* Clock Phase Mode
 *
 * LEADING_SAMPLE >> sample at leading and setup at trailing
 * LEADING_SETUP >> sample at trailing and setup at rising
 *
 */

#define CLOCK_PHASE LEADING_SAMPLE

/* CLOCK
 *
 * MODE_F/4
 * MODE_F/16
 * MODE_F/64
 * MODE_F/128
 */

#define SPI_FREQUENCY  MODE_F_16

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
