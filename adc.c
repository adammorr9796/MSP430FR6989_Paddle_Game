/*
 * adc.c
 *
 *  Created on: Feb 6, 2021
 *      Author: Adam Morrison
 */

#include <adc.h>

void adc_init() {
    ADC12CTL0 = 0b0010001000000000;         // 16 cycles SaH time, rising edge sampling, ADC off, Enable conversion = no, Start conversion = no
    ADC12CTL1 = 0b0000001000011000;         // Predivide by 1, software enabled start conversion, sample src signal = timer, clk div = 1, clk sel = SMCLK, single channel single conversion
    ADC12CTL2 = 0b0000000000010000;         // ADC resolution = 10 bit, binary unsigned format

    ADC12MCTL0 = 0x0007;                    // A7, P8.4
    ADC12CTL0 |= ADC12ON;
}

unsigned int adc_read_val() {
    ADC12CTL0 |= ADC12ENC;                  // enable conversion
    ADC12CTL0 |= ADC12SC;                   // start conversion

    return ADC12MEM0;
}
