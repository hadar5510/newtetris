#pragma once
#include <stdbool.h>
#include "gameConfig.h"

class Point
{
public:
	int x;
	int y;
	int diff_x;
	int diff_y;

	Point(int x, int y) {
		this->init(x, y);
	}
	Point() {
		this->init(0, 0);
	}
	void init(int x, int y);
	void draw(char ch, int backcolor);
	void move(GameConfig::eKeys key);
};
