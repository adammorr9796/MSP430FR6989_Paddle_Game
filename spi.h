/*
 * spi.h
 *
 *  Created on: Jan 18, 2021
 *      Author: Adam Morrison
 */

/***** Header Files *****/
#include <msp430fr6989.h>

#ifndef SPI_H_
#define SPI_H_

#define ENABLE_PINS 0xFFFE

/***** Function Prototypes *****/

/******************************************************************************
 * spi_init():
 *
 * Enable SPI peripheral configured in 4 pin, MSB first, 8-bit master mode.
 ******************************************************************************/
void spi_init(void);

/******************************************************************************
 * spi_write_cmd():
 *
 * Pull Data/Cmd pin on SPI slave to low for command and send 8 bit
 * command along with clock.
 ******************************************************************************/
void spi_write_cmd(unsigned char);

/******************************************************************************
 * spi_write_data():
 *
 * Pull Data/Cmd pin on SPI slave to high for data and send 8 bit
 * piece of data along with clock.
 ******************************************************************************/
void spi_write_data(unsigned char);

#endif /* SPI_H_ */
