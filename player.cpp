#include "player.h"

//initializes player
void player::init(int minX, int minY, char left, char right, char drop, char rotateClock, char rotateAntiClock, bool flag)
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