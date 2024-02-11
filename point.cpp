#include "point.h"
#include "general.h"

#include <iostream>
#include <Windows.h>
using namespace std;


void point::init(int x, int y)
{
	this->x = x;
	this->y = y;
	diff_x = 1;
	diff_y = 0;
}

