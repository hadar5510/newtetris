#pragma once
#include "point.h"
#include "general.h"

class player;

class shape
{

	int type;
	char ch;
	int rotateNum;
	char shapeDirection; //N S W E



public:


	point body[4];


	void init(int minX, int minY, int shapetype);

	void printShape(int x, int y, char ch, int minRow);


	void drop();
	void rotate(int direction);

	int getType() { return type; }

	void move(char keyPressed);

};