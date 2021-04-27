/*
 * main.c
 *
 * Created on: Jan 16, 2021
 *     Author: Adam Morrison
 *
 *---------------------------------
 * MSP430FR6989 Paddle Game Project
 *---------------------------------
 */

#include <game.h>

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;                   // stop watchdog timer
    PM5CTL0 = ENABLE_PINS;                      // enable pins

    CSCTL0 = 0xA500;
    CSCTL1 |= 0b0000000001000110;               // DCOCLK set to 8 MHz
    CSCTL2 |= 0b0000000000110011;               // SMLCK and MCLK set to DCOCLK
    CSCTL3 |= 0b0000000000000000;

	game_init();

	int game_over = -1;

	while(game_over == -1) {
	    game_over = game_loop();
	}

    return 0;
}
