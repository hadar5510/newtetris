#pragma once
#include <stdbool.h>
#include "general.h"

class point
{
public:
	int x;
	int y;
	int diff_x;
	int diff_y;


	point(int x, int y) {
		this->init(x, y);
	}
	point() {
		this->init(0, 0);
	}

	void init(int x, int y);
	void draw(char ch, int backcolor);

};