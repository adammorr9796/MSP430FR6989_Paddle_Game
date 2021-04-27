/*
 * adc.h
 *
 *  Created on: Feb 6, 2021
 *      Author: Adam Morrison
 */

/***** Header Files *****/
#include <msp430fr6989.h>

#ifndef ADC_H_
#define ADC_H_

/***** Function Prototypes *****/

/******************************************************************************
 * adc_init():
 *
 * Set up and enable ADC peripheral.
 ******************************************************************************/
void adc_init();

/******************************************************************************
 * adc_read_val():
 *
 * Return the current analog value as a number between 0
 * and 1023 (10 bit resolution).
 ******************************************************************************/
unsigned int adc_read_val();

#endif /* ADC_H_ */
