/*
 * lcd.h
 *
 *  Created on: Feb 6, 2021
 *      Author: Adam Morrison
 */

#ifndef LCD_H_
#define LCD_H_

/***** Header Files *****/
#include <spi.h>

/***** Function Prototypes *****/

/******************************************************************************
 * lcd_init():
 *
 * Wake up LCD, turn display ON, set color format to 16 bit.
 ******************************************************************************/
void lcd_init();

/******************************************************************************
 * lcd_set_rect_area():
 *
 * Set column and page addresses to define current LCD area to be updated.
 ******************************************************************************/
void lcd_set_rect_area(unsigned int xStart, unsigned int xEnd, unsigned int yStart, unsigned int yEnd);

/******************************************************************************
 * lcd_color_rect_fill():
 *
 * Send color data to LCD for each pixel in current column/page area.
 ******************************************************************************/
void lcd_color_rect_fill(long size, unsigned char c_bits_1, unsigned char c_bits_2);

/******************************************************************************
 * lcd_invert_display():
 *
 * Invert current color scheme.
 ******************************************************************************/
void lcd_invert_display(int state);

#endif /* LCD_H_ */
