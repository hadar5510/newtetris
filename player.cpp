#include "player.h"



Player::Player(int minX, int minY, char left, char right, char drop, char rotateClock, char rotateAntiClock, bool flag, bool isColoredGame) : board(minX, minY, isColoredGame)
{
	this->minX = minX;
	this->minY = minY;
	this->left = left;
	this->right = right;
	this->drop = drop;
	this->rotateAntiClock = rotateAntiClock;
	this->rotateClock = rotateClock;
	this->flag = flag;
	
}