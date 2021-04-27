/*
 * game.c
 *
 *  Created on: Jan 27, 2021
 *      Author: Adam Morrison
 */

#include <game.h>

const unsigned int rand_start_lut[] = {
    202, 131, 118, 120, 187, 201, 86, 104, 196, 162, 160, 60, 8, 33, 232, 210
};

const char pixel_map[] = {
0,0,0,1,1,1,1,1,2,
2,2,2,2,3,3,3,3,3,4,
4,4,4,5,5,5,5,5,6,6,
6,6,6,7,7,7,7,7,8,8,
8,8,9,9,9,9,9,10,10,10,
10,10,11,11,11,11,11,12,12,12,
12,13,13,13,13,13,14,14,14,14,
14,15,15,15,15,15,16,16,16,16,
17,17,17,17,17,18,18,18,18,18,
19,19,19,19,19,20,20,20,20,21,
21,21,21,21,22,22,22,22,22,23,
23,23,23,23,24,24,24,24,25,25,
25,25,25,26,26,26,26,26,27,27,
27,27,27,28,28,28,28,29,29,29,
29,29,30,30,30,30,30,31,31,31,
31,31,32,32,32,32,32,33,33,33,
33,34,34,34,34,34,35,35,35,35,
35,36,36,36,36,36,37,37,37,37,
38,38,38,38,38,39,39,39,39,39,
40,40,40,40,40,41,41,41,41,42,
42,42,42,42,43,43,43,43,43,44,
44,44,44,44,45,45,45,45,46,46,
46,46,46,47,47,47,47,47,48,48,
48,48,48,49,49,49,49,50,50,50,
50,50,51,51,51,51,51,52,52,52,
52,52,53,53,53,53,54,54,54,54,
54,55,55,55,55,55,56,56,56,56,
56,57,57,57,57,58,58,58,58,58,
59,59,59,59,59,60,60,60,60,60,
61,61,61,61,61,62,62,62,62,63,
63,63,63,63,64,64,64,64,64,65,
65,65,65,65,66,66,66,66,67,67,
67,67,67,68,68,68,68,68,69,69,
69,69,69,70,70,70,70,71,71,71,
71,71,72,72,72,72,72,73,73,73,
73,73,74,74,74,74,75,75,75,75,
75,76,76,76,76,76,77,77,77,77,
77,78,78,78,78,79,79,79,79,79,
80,80,80,80,80,81,81,81,81,81,
82,82,82,82,83,83,83,83,83,84,
84,84,84,84,85,85,85,85,85,86,
86,86,86,87,87,87,87,87,88,88,
88,88,88,89,89,89,89,89,90,90,
90,90,91,91,91,91,91,92,92,92,
92,92,93,93,93,93,93,94,94,94,
94,94,95,95,95,95,96,96,96,96,
96,97,97,97,97,97,98,98,98,98,
98,99,99,99,99,100,100,100,100,100,
101,101,101,101,101,102,102,102,102,102,
103,103,103,103,104,104,104,104,104,105,
105,105,105,105,106,106,106,106,106,107,
107,107,107,108,108,108,108,108,109,109,
109,109,109,110,110,110,110,110,111,111,
111,111,112,112,112,112,112,113,113,113,
113,113,114,114,114,114,114,115,115,115,
115,116,116,116,116,116,117,117,117,117,
117,118,118,118,118,118,119,119,119,119,
120,120,120,120,120,121,121,121,121,121,
122,122,122,122,122,123,123,123,123,123,
124,124,124,124,125,125,125,125,125,126,
126,126,126,126,127,127,127,127,127,128,
128,128,128,129,129,129,129,129,130,130,
130,130,130,131,131,131,131,131,132,132,
132,132,133,133,133,133,133,134,134,134,
134,134,135,135,135,135,135,136,136,136,
136,137,137,137,137,137,138,138,138,138,
138,139,139,139,139,139,140,140,140,140,
141,141,141,141,141,142,142,142,142,142,
143,143,143,143,143,144,144,144,144,145,
145,145,145,145,146,146,146,146,146,147,
147,147,147,147,148,148,148,148,149,149,
149,149,149,150,150,150,150,150,151,151,
151,151,151,152,152,152,152,153,153,153,
153,153,154,154,154,154,154,155,155,155,
155,155,156,156,156,156,156,157,157,157,
157,158,158,158,158,158,159,159,159,159,
159,160,160,160,160,160,161,161,161,161,
162,162,162,162,162,163,163,163,163,163,
164,164,164,164,164,165,165,165,165,166,
166,166,166,166,167,167,167,167,167,168,
168,168,168,168,169,169,169,169,170,170,
170,170,170,171,171,171,171,171,172,172,
172,172,172,173,173,173,173,174,174,174,
174,174,175,175,175,175,175,176,176,176,
176,176,177,177,177,177,178,178,178,178,
178,179,179,179,179,179,180,180,180,180,
180,181,181,181,181,182,182,182,182,182,
183,183,183,183,183,184,184,184,184,184,
185,185,185,185,185,186,186,186,186,187,
187,187,187,187,188,188,188,188,188,189,
189,189,189,189,190,190,190,190,191,191,
191,191,191,192,192,192,192,192,193,193,
193,193,193,194,194,194,194,195,195,195,
195,195,196,196,196,196,196,197,197,197,
197,197,198,198,198,198,199,199,199,199,
199,200,200,200,200,200,201,201,201,201,
201,202,202,202,202,203,203,203,203,203,
204,204,204,204,204,205,205,205,205,205,
206,206,206,206,207,207,207,207,207,208,
208,208,208,208,209,209,209,209,209,210,
210,210,210,211,211,211,211,211,212,212,
212,212,212,213,213,213,213,213,214,214,
214,214,215,215,215
};

void game_init() {
    spi_init();
    adc_init();
    lcd_init();

    lcd_invert_display(0);                                      // ensure normal color scheme

    lcd_set_rect_area(0x0000, 0x00EF, 0x0000, 0x013F);          // fill frame buffer with all black pixels
    lcd_color_rect_fill(76800, 0x00, 0x00);

    Ball.x1 = 100;
    Ball.x2 = 104;
    Ball.y1 = 50;
    Ball.y2 = 54;
    Ball.x_dir = 1;
    Ball.y_dir = -1;
    Ball.score = -1;
    Ball.speed = 4;

    User_Paddle.x1 = 110;
    User_Paddle.x2 = 134;
    User_Paddle.y1 = 0;
    User_Paddle.y2 = 4;
    User_Paddle.x1_prev = User_Paddle.x1;
    User_Paddle.x2_prev = User_Paddle.x2;
    User_Paddle.y1_prev = User_Paddle.y1;
    User_Paddle.y2_prev = User_Paddle.y2;
    User_Paddle.x_dir = 1;
    User_Paddle.y_dir = 1;
    User_Paddle.score = 0;
    User_Paddle.score_y_offset = 130;

    AI_Paddle.x1 = 110;
    AI_Paddle.x2 = 134;
    AI_Paddle.y1 = 315;
    AI_Paddle.y2 = 319;
    AI_Paddle.x1_prev = AI_Paddle.x1;
    AI_Paddle.x2_prev = AI_Paddle.x2;
    AI_Paddle.y1_prev = AI_Paddle.y1;
    AI_Paddle.y2_prev = AI_Paddle.y2;
    AI_Paddle.x_dir = 1;
    AI_Paddle.y_dir = 1;
    AI_Paddle.score = 0;
    AI_Paddle.score_y_offset = 190;
    AI_Paddle.speed = 3;
}

int game_loop() {
    game_recalculate_positions();
    game_detect_collisions();
    game_update_frame();
    return game_check_win_condition();
}

void game_update_frame() {
    game_draw_paddle(&User_Paddle);
    game_draw_paddle(&AI_Paddle);
    game_draw_ball();
    game_draw_score(&User_Paddle);
    game_draw_score(&AI_Paddle);
}

void game_recalculate_positions() {
    // recalculate ball position based on direction
    if (Ball.x_dir == 1) {
        Ball.x1_prev = Ball.x1;
        Ball.x2_prev = Ball.x2;
        Ball.x1 = Ball.x1 + Ball.speed;
        Ball.x2 = Ball.x2 + Ball.speed;
    }

    if (Ball.x_dir == -1) {
        Ball.x1_prev = Ball.x1;
        Ball.x2_prev = Ball.x2;
        Ball.x1 = Ball.x1 - Ball.speed;
        Ball.x2 = Ball.x2 - Ball.speed;
    }

    if (Ball.y_dir == 1) {
        Ball.y1_prev = Ball.y1;
        Ball.y2_prev = Ball.y2;
        Ball.y1 = Ball.y1 + Ball.speed;
        Ball.y2 = Ball.y2 + Ball.speed;
    }

    if (Ball.y_dir == -1) {
        Ball.y1_prev = Ball.y1;
        Ball.y2_prev = Ball.y2;
        Ball.y1 = Ball.y1 - Ball.speed;
        Ball.y2 = Ball.y2 - Ball.speed;
    }

    // special case for ball past left or right edge of screen
    if (Ball.x1 < 0) {
        Ball.x1 = 0;
        Ball.x2 = 4;
    }

    if (Ball.x2 > 239) {
        Ball.x1 = 235;
        Ball.x2 = 239;
    }

    // recalculate user position - read value from potentiometer
    User_Paddle.x1_prev = User_Paddle.x1;
    User_Paddle.x2_prev = User_Paddle.x2;
    User_Paddle.x1 = pixel_map[adc_read_val()];
    User_Paddle.x2 = User_Paddle.x1+24;

    // recalculate AI position
    // go to opposite corner while ball is on player side, otherwise track movement
    AI_Paddle.x1_prev = AI_Paddle.x1;
    AI_Paddle.x2_prev = AI_Paddle.x2;

    if (Ball.y1 > 160) {
        if (Ball.x2 < AI_Paddle.x1+12) {
            AI_Paddle.x1 = AI_Paddle.x1 - AI_Paddle.speed;
            AI_Paddle.x2 = AI_Paddle.x2 - AI_Paddle.speed;
        }

        if (Ball.x1 > AI_Paddle.x2-12) {
            AI_Paddle.x1 = AI_Paddle.x1 + AI_Paddle.speed;
            AI_Paddle.x2 = AI_Paddle.x2 + AI_Paddle.speed;
        }
    }

    if (Ball.y1 <= 160) {
        if (Ball.x2 < AI_Paddle.x1+12  && Ball.x_dir == 1) {
            AI_Paddle.x1 = AI_Paddle.x1 + AI_Paddle.speed;
            AI_Paddle.x2 = AI_Paddle.x2 + AI_Paddle.speed;
        }

        if (Ball.x1 > AI_Paddle.x2-12  && Ball.x_dir == -1) {
            AI_Paddle.x1 = AI_Paddle.x1 - AI_Paddle.speed;
            AI_Paddle.x2 = AI_Paddle.x2 - AI_Paddle.speed;
        }
    }

    // special case for AI paddle past top or bottom edge of screen
    int offset = 0;
    if (AI_Paddle.x1 <= 0) {
        offset = AI_Paddle.x1*(-1);
        AI_Paddle.x1 = AI_Paddle.x1 + offset;
        AI_Paddle.x2 = AI_Paddle.x2 + offset;
    }

    if (AI_Paddle.x2 >= 239) {
        offset = AI_Paddle.x2-239;
        AI_Paddle.x1 = AI_Paddle.x1 - offset;
        AI_Paddle.x2 = AI_Paddle.x2 - offset;
    }
}

void game_detect_collisions() {
    // detect collisions with sides of screen and change direction if necessary
    if (Ball.x1 == 0) {                         // Ball touching top of screen
        Ball.x_dir = 1;
    }

    if (Ball.x2 == 239) {                       // Ball touching bottom of screen
        Ball.x_dir = -1;
    }

    if (Ball.y1 <= 0) {                         // Ball touching left of screen
        AI_Paddle.score++;
        game_reset_ball_position();
    }

    if (Ball.y2 >= 319) {                       // Ball touching right of screen
        User_Paddle.score++;
        game_reset_ball_position();
    }

    // detect collision with user paddle
    if (Ball.x1 >= User_Paddle.x1 && Ball.x2 <= User_Paddle.x2 && Ball.y1 <= User_Paddle.y2+1) {
        Ball.y_dir = 1;
    }

    // detect collision with AI paddle
    if (Ball.x1 >= AI_Paddle.x1 && Ball.x2 <= AI_Paddle.x2 && Ball.y2 >= AI_Paddle.y1-1) {
        Ball.y_dir = -1;
    }
}

void game_reset_ball_position() {
    static int rand_val = 0;

    Ball.x1 = rand_start_lut[rand_val];
    Ball.x2 = rand_start_lut[rand_val]+4;
    Ball.y1 = 157;
    Ball.y2 = 161;

    rand_val++;
}

void game_draw_ball() {
    lcd_set_rect_area(Ball.x1_prev, Ball.x2_prev, Ball.y1_prev, Ball.y2_prev);      // clear ball by setting all pixels at prev position to black
    lcd_color_rect_fill(30, 0x00, 0x00);
    lcd_set_rect_area(Ball.x1, Ball.x2, Ball.y1, Ball.y2);                          // re-draw ball by drawing ball in white pixels at current position
    lcd_color_rect_fill(30, 0xFF, 0xFF);
}

void game_draw_paddle(Sprite* Curr_Player) {                                                                                                                  // otherwise, just rewrite all pixels at the prev position and write all pixels at new position
    lcd_set_rect_area(Curr_Player->x1_prev, Curr_Player->x2_prev, Curr_Player->y1_prev, Curr_Player->y2_prev);
    lcd_color_rect_fill(150, 0x00, 0x00);
    lcd_set_rect_area(Curr_Player->x1, Curr_Player->x2, Curr_Player->y1, Curr_Player->y2);
    lcd_color_rect_fill(150, 0xFF, 0xFF);
}

void game_draw_score(Sprite* Curr_Player) {
    // top segment
    lcd_set_rect_area(0,0,1+Curr_Player->score_y_offset,8+Curr_Player->score_y_offset);

    if (Curr_Player->score == 0 || Curr_Player->score == 2 || Curr_Player->score == 3 || Curr_Player->score == 5 || Curr_Player->score == 6 || Curr_Player->score == 7 || Curr_Player->score == 8 || Curr_Player->score == 9) {
        lcd_color_rect_fill(10, 0xFF, 0xFF);
    }
    else {
        lcd_color_rect_fill(10, 0x00, 0x00);
    }

    // upper left segment
    lcd_set_rect_area(1,8,0+Curr_Player->score_y_offset,0+Curr_Player->score_y_offset);

    if (Curr_Player->score == 0 || Curr_Player->score == 4 || Curr_Player->score == 5 || Curr_Player->score == 6 || Curr_Player->score == 8 || Curr_Player->score == 9) {
        lcd_color_rect_fill(10, 0xFF, 0xFF);
    }
    else {
        lcd_color_rect_fill(10, 0x00, 0x00);
    }

    // upper right segment
    lcd_set_rect_area(1,8,9+Curr_Player->score_y_offset,9+Curr_Player->score_y_offset);

    if (Curr_Player->score == 0 || Curr_Player->score == 1 || Curr_Player->score == 2 || Curr_Player->score == 3 || Curr_Player->score == 4 || Curr_Player->score == 7 || Curr_Player->score == 8 || Curr_Player->score == 9) {
        lcd_color_rect_fill(10, 0xFF, 0xFF);
    }
    else {
        lcd_color_rect_fill(10, 0x00, 0x00);
    }

    // middle segment
    lcd_set_rect_area(9,9,1+Curr_Player->score_y_offset,8+Curr_Player->score_y_offset);

    if (Curr_Player->score == 2 || Curr_Player->score == 3 || Curr_Player->score == 4 || Curr_Player->score == 5 || Curr_Player->score == 6 || Curr_Player->score == 8 || Curr_Player->score == 9) {
        lcd_color_rect_fill(10, 0xFF, 0xFF);
    }
    else {
        lcd_color_rect_fill(10, 0x00, 0x00);
    }

    // lower left segment
    lcd_set_rect_area(10,18,0+Curr_Player->score_y_offset,0+Curr_Player->score_y_offset);

    if (Curr_Player->score == 0 || Curr_Player->score == 2 || Curr_Player->score == 6 || Curr_Player->score == 8) {
        lcd_color_rect_fill(10, 0xFF, 0xFF);
    }
    else {
        lcd_color_rect_fill(10, 0x00, 0x00);
    }

    // lower right segment
    lcd_set_rect_area(10,18,9+Curr_Player->score_y_offset,9+Curr_Player->score_y_offset);

    if (Curr_Player->score == 0 || Curr_Player->score == 1 || Curr_Player->score == 3 || Curr_Player->score == 4 || Curr_Player->score == 5 || Curr_Player->score == 6 || Curr_Player->score == 7 || Curr_Player->score == 8 || Curr_Player->score == 9) {
        lcd_color_rect_fill(10, 0xFF, 0xFF);
    }
    else {
        lcd_color_rect_fill(10, 0x00, 0x00);
    }

    // bottom segment
    lcd_set_rect_area(19,19,1+Curr_Player->score_y_offset,8+Curr_Player->score_y_offset);

    if (Curr_Player->score == 0 || Curr_Player->score == 2 || Curr_Player->score == 3 || Curr_Player->score == 5 || Curr_Player->score == 6 || Curr_Player->score == 8 || Curr_Player->score == 9) {
        lcd_color_rect_fill(10, 0xFF, 0xFF);
    }
    else {
        lcd_color_rect_fill(10, 0x00, 0x00);
    }
}

int game_check_win_condition() {
    unsigned int i,j = 0;

    if (User_Paddle.score == 9 || AI_Paddle.score == 9) {
        for (j = 0; j < 5; j++) {
                for (i=0;i<65535;i++) {}            // TODO: replace with timer hardware delay
                for (i=0;i<65535;i++) {}
                for (i=0;i<65535;i++) {}
                for (i=0;i<65535;i++) {}
                for (i=0;i<65535;i++) {}
                lcd_invert_display(0);
                for (i=0;i<65535;i++) {}
                for (i=0;i<65535;i++) {}
                for (i=0;i<65535;i++) {}
                for (i=0;i<65535;i++) {}
                for (i=0;i<65535;i++) {}
                lcd_invert_display(1);
        }
        return 1;
    }
    return -1;
}
