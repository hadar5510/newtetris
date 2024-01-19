#pragma once
#include "shape.h"
#include "general.h"


class board
{

private:
	void deleteLine(int line);

public:
	static constexpr int gameWidth = 12;
	static constexpr int gameHeight = 18;
	char board[gameHeight][gameWidth];
	int minRow;

	void setMinRow(int row) { minRow = row; } //lo yodim
	int getMinRow() { return minRow; }


	bool checkFullLines(shape shape, int line);


	bool checkLegalMove(shape shape, int minX, int minY, char ch);
	void saveShape(shape shape, int x, int y);
	void deleteShape(shape shape, int x, int y);
	void init();
	void printBoard(int minX, int minY);
	void drawBorder(int minX, int minY);


};

