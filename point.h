#ifndef __POINT_H
#define __POINT_H
#include <stdbool.h>
#include "general.h"

class Point
{
private:
	int x;
	int y;

public:



	Point(int x, int y) {
		this->init(x, y);
	}
	Point() {
		this->init(0, 0);
	}

	void init(int x, int y);

	friend class Shape;
	friend class Board;

};
#endif