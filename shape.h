#ifndef __SHAPE_H
#define __SHAPE_H
#include "point.h"
#include "general.h"

class player;

class shape
{
	int type;
	char shapeDirection; //N S W E = (north south west east - for the direction calculation)

public:
	point body[4];

	int getShapeType() { return type; }
	void init(int minX, int minY, int shapetype);
	void rotate(int direction);
	void move(char keyPressed);
};

#endif