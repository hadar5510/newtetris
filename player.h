#pragma once
#include "board.h"
#include "shape.h"
#include "general.h"


class player
{
	int minX, minY; //start of player board
	char left, right, drop, rotateClock, rotateAntiClock;
	bool flag;
	

public:
	board board;
	shape currShape;

	void init(int minX, int minY, char left, char right, char drop, char rotateClock, char rotateAntiClock, bool flag);

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