#pragma once
#include "point.h"
#include "general.h"

class player;

class shape
{

	int type;
	char ch;
	int rotateNum;
	void shapeFirst();


public:


	point body[4];

	void init(int minX, int minY, int shapetype);
	void printShape(int x, int y, char ch, int minRow);
	void rotate(int direction);

	int getType() { return type; }

	void move(player& player, char keyPressed);

};