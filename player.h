#ifndef __PLAYER_H
#define __PLAYER_H
#include "board.h"
#include "shape.h"
#include "general.h"


class Player
{
private:
	int minX, minY;											//start of the player board in the screen
	char left, right, drop, rotateClock, rotateAntiClock;	//player keys
	mutable bool flag;												//check if player won the game


public:
	Board board;
	Shape currShape;

	Player(int minX, int minY, char left, char right, char drop, char rotateClock, char rotateAntiClock, bool flag, bool isColoredGame);


	//initializing player keys

	//functions to get the player's private components
	const int getMinX() const { return minX; }
	const int getMinY() const { return minY; }
	const char getLeft() const { return left; }
	const char getRight() const { return right; }
	const char getDrop() const { return drop; }
	const char getRotateClock() const { return rotateClock; }
	const char getRotateAntiClock() const { return rotateAntiClock; }
	bool getFlag() { return flag; }
	void setFlag(bool flag) { this->flag = flag; }


};

#endif