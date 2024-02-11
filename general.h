#ifndef __GENERAL_H
#define __GENERAL_H



enum shapeTypes { L_LEFT, L_RIGHT, T_SHAPE, LINE, SQUARE, Z_LEFT, Z_RIGHT };
enum directions { DOWN, CLOCKWISE, ANTI_CLOCKWISE };
enum menuKeys { NEW_GAME = '1', CONTINUE_GAME = '2', INSTRUCTIONS = '8', EXIT = '9', ESC = 27 };
enum player1Keys { P1_LEFT = 'A', P1_RIGHT = 'D', P1_DROP = 'X', P1_ROTATE_CLOCK = 'S', P1_ROTATE_ANTI_CLOCK = 'W' };
enum player2Keys { P2_LEFT = 'J', P2_RIGHT = 'L', P2_DROP = 'M', P2_ROTATE_CLOCK = 'K', P2_ROTATE_ANTI_CLOCK = 'I' };
enum boardConfig { GAME_WIDTH = 12, GAME_HEIGHT = 18, MIN_X = 30, MIN_Y = 6 };



void gotoxy(int x, int y);
void clrscr();


#endif 