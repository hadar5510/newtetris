#ifndef __SHAPE_H
#define __SHAPE_H
#include "point.h"
#include "general.h"

class Player;

class Shape
{
	Point body[4];
	int type;
	char shapeDirection; //N S W E = (north south west east - for the direction calculation)
	int color;

	void rotateClock();
	void rotateAntiClock();

public:

	/*shape(const shape& other);*/

	const char getShapeDirection() const { return shapeDirection; }
	void setShapeDirection(char direction) { this->shapeDirection = direction; }
	const int getShapeType() const { return type; }
	void init(int minX, int minY, int shapetype);
	/*int initColor(bool backroundColor);*/

	int getColor() { return color; }

	void rotate(int direction);

	void move(char keyPressed);

	friend class Board;

};

#endif