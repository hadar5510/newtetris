#ifndef __GENERAL_H
#define __GENERAL_H


#define DOWN 'v'
#define ESC 27
#define NEW_GAME '1'
#define CONTINUE_GAME '2'
#define INSTRUCTIONS '8'
#define EXIT '9'
#define L_LEFT 0
#define L_RIGHT 1
#define T_SHAPE 2
#define LINE 3
#define SQUARE 4
#define Z_LEFT 5
#define Z_RIGHT 6
#define CLOCKWISE 1
#define ANTI_CLOCKWISE 2


static constexpr int GAME_WIDTH = 12;
static constexpr int GAME_HEIGHT = 18;

static constexpr int MIN_X = 30;
static constexpr int MIN_Y = 6;

void gotoxy(int x, int y);
void clrscr();


#endif 