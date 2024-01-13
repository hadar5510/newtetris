#pragma once
#include <stdbool.h>
#include "point.h"

class shapes
{
	
public:
	Point body[4];
	char ch;
	int backgroundcolor;
	int type; //1 is line 2 is cube
	void init(const Point& head, char ch, int color);
	void move(GameConfig::eKeys direction);
	bool legalmove(int direction);
};

