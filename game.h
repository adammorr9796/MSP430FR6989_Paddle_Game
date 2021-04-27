/*
 * game.h
 *
 *  Created on: Jan 27, 2021
 *      Author: Adam Morrison
 */

/***** Header Files *****/
#include <msp430fr6989.h>
#include <spi.h>
#include <adc.h>
#include <lcd.h>

#ifndef GAME_H_
#define GAME_H_

/***** Structs *****/
typedef struct Sprite {
    int x1;
    int x2;
    int y1;
    int y2;
    int x1_prev;
    int x2_prev;
    int y1_prev;
    int y2_prev;
    int x_dir;
    int y_dir;
    int score;
    int score_y_offset;
    int speed;
} Sprite;

Sprite Ball;
Sprite User_Paddle;
Sprite AI_Paddle;

/***** Function Prototypes *****/

/******************************************************************************
 * game_init():
 *
 * Initialize SPI, LCD, and ADC. Set up Sprites and display black screen.
 ******************************************************************************/
void game_init();

/******************************************************************************
 * game_loop():
 *
 * Main driver function. Calls other game functions to recalculate positions,
 * detect collisions, update frame, and check for win condition. Return 1 if
 * game is over, -1 if game is not over.
 ******************************************************************************/
int game_loop();

/******************************************************************************
 * game_recalculate_positions():
 *
 * Calculate and update Sprite variables with new positions for next
 * frame update.
 ******************************************************************************/
void game_recalculate_positions();

/******************************************************************************
 * game_detect_collisions():
 *
 * Check and handle cases where the ball or paddles have collided with
 * each other or sides of the screen.
 ******************************************************************************/
void game_detect_collisions();

/******************************************************************************
 * game_draw_paddle():
 *
 * Update the LCD with the new paddle positions.
 ******************************************************************************/
void game_draw_paddle(Sprite* Curr_Player);

/******************************************************************************
 * game_draw_ball():
 *
 * Update the LCD with the new ball position.
 ******************************************************************************/
void game_draw_ball();

/******************************************************************************
 * game_draw_score():
 *
 * Update the LCD with the user and AI scores.
 ******************************************************************************/
void game_draw_score(Sprite* Curr_Player);

/******************************************************************************
 * game_reset_ball_position():
 *
 * Look up new ball position after a point is scored.
 ******************************************************************************/
void game_reset_ball_position();

/******************************************************************************
 * game_update_frame():
 *
 * Calls other functions to write data to the LCD for scores and new paddle
 * and ball positions.
 ******************************************************************************/
void game_update_frame();

/******************************************************************************
 * game_check_win_condition():
 *
 * Display winning screen patterns and return -1 if game is over,
 * else return 1.
 ******************************************************************************/
int game_check_win_condition();

#endif /* GAME_H_ */
