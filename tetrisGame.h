#pragma once


#include "shapes.h"

class tetrisGame
{
	Shape shape;

public:
	void init();
	void run();
	void freeMemory();
};
