#pragma once


class shapes;

class tetrisGame
{
	shapes* allSnakes;
	int numOfSnakes;

public:
	void init(int num);
	void run();
	void freeMemory();

};

