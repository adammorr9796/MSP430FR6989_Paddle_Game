/*
 * lcd.c
 *
 *  Created on: Feb 6, 2021
 *      Author: Adam Morrison
 */

#include <lcd.h>

void lcd_init() {
    spi_write_cmd(0x11);                             // sleep OUT
    spi_write_cmd(0x29);                             // display mode ON

    spi_write_cmd(0x3A);                             // pixel format set
    spi_write_data(0b00000101);                      // 16 bit color
}

void lcd_set_rect_area(unsigned int xStart, unsigned int xEnd, unsigned int yStart, unsigned int yEnd) {
    spi_write_cmd(0x2A);                             // column address set - default 0x0000 00EF
    spi_write_data(xStart >> 8);                     // SC [15:8]
    spi_write_data(xStart & 0x00FF);                 // SC [7:0]
    spi_write_data(xEnd >> 8);                       // EC [15:8]
    spi_write_data(xEnd & 0x00FF);                   // EC [7:0]

    spi_write_cmd(0x2B);                             // page address set - default 0x0000 013F
    spi_write_data(yStart >> 8);                     // SP [15:8]
    spi_write_data(yStart & 0x00FF);                 // SP [7:0]
    spi_write_data(yEnd >> 8);                       // EP [15:8]
    spi_write_data(yEnd & 0x00FF);                   // EP [7:0]
}

void lcd_color_rect_fill(long size, unsigned char c_bits_1, unsigned char c_bits_2) {
    spi_write_cmd(0x2C);                             // frame buffer write

    long count;

    for(count = 0; count < size; count++) {
        spi_write_data(c_bits_2);                    // first 8 bits of color for current pixel
        spi_write_data(c_bits_1);                    // second 8 bits of color for current pixel
    }

    spi_write_cmd(0x00);                             // end frame buffer write
}

void lcd_invert_display(int state) {
    if (state == 1) {
        spi_write_cmd(0x21);                         // display inversion ON
    }
    else if (state == 0) {
        spi_write_cmd(0x20);                         // display inversion OFF
    }
}
