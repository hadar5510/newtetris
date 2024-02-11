#ifndef __PLAYER_H
#define __PLAYER_H
#include "board.h"
#include "shape.h"
#include "general.h"


class player
{
	int minX, minY;											//start of the player board in the screen
	char left, right, drop, rotateClock, rotateAntiClock;	//player keys
	bool flag;												//check if player won the game


public:
	board board;
	shape currShape;

	//initializing player keys
	void init(int minX, int minY, char left, char right, char drop, char rotateClock, char rotateAntiClock, bool flag);

	//functions to get the player's private components
	int getMinX() { return minX; }
	int getMinY() { return minY; }
	char getLeft() { return left; }
	char getRight() { return right; }
	char getDrop() { return drop; }
	char getRotateClock() { return rotateClock; }
	char getRotateAntiClock() { return rotateAntiClock; }
	bool getFlag() { return flag; }
	void setFlag(bool flag) { this->flag = flag; }


};

#endif