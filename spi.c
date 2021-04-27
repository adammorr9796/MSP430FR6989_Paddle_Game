/*
 * spi.c
 *
 *  Created on: Jan 27, 2021
 *      Author: Adam Morrison
 *
 * ----------------------
 * MSP430FR6989       LCD
 * ----------------------
 * 3V3             => Vin
 * GND             => GND
 * P1.3 (GPIO)     => D/C
 * P1.4 (UCB0CLK)  => CLK
 * P1.5 (UCB0STE)  => CS
 * P1.6 (UCB0SIMO) => MOSI
 *
 */

#include <spi.h>

void spi_init() {
    P1DIR = 0b01111000;                         // all pins being used on P1 are outputs (all SPI related pins that we are using are on P1)
    P1SEL1 = 0b00000000;
    P1SEL0 = 0b01110000;                        // P1SEL1 & P1SEL0 set peripheral to use
                                                // P1.4, P1.5, P1.6  set to 0b01 - primary peripheral (SPI peripherals) selected
                                                // P1.3 set to 0b00 - GPIO selected

    /* UCB0CTLW0 Register Setup */
    UCB0CTLW0 = 0x0001;                         // eUSCI module disabled; eUSCI reset
    UCB0CTLW0 = 0b0010110110000011;             // configure SPI options - p. 816 - 4 pin, CS active low, 8 bit data, MSB first, master mode
    UCB0BRW = 0x01;                             // set SPI clock (bit rate) to SMCLK divided by this register number
    UCB0CTLW0 &= ~(BIT0);                       // eUSCI module enabled; ready to receive and transmit
}

void spi_write_cmd(unsigned char x) {
    P1OUT &= ~BIT3;                             // set D/C to 'C' (LOW) for a command
    UCB0IFG = 0x00;                             // reset TX buffer interrupt flag
    UCB0TXBUF = x;                              // write command
}

void spi_write_data(unsigned char y) {
    P1OUT |= BIT3;                              // set D/C to 'D' (HIGH) for data
    UCB0IFG = 0x00;                             // reset TX buffer interrupt flag
    UCB0TXBUF = y;                              // write command
}
