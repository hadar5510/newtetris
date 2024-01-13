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


	void init(int x, int y);
	void draw(char ch, int backcolor);
	void move(GameConfig::eKeys key);
};

