#pragma once
#include "shape.h"
#include "general.h"


class board
{

private:

public:
	static constexpr int gameWidth = 12;
	static constexpr int gameHeight = 18;
	char board[gameHeight][gameWidth];
	int minRow;

	void setMinRow(int row) { minRow = row; } //lo yodim
	int getMinRow() { return minRow; }


	int checkDrop(shape shape, int minX, int minY);
	void checkFullLines();
	void deleteLine(int line);
	bool checkShapeMoveLeftRight(shape shape, int minX, int minY, char direction);
	bool checkShapeGoDown(shape shape, int minX, int minY);
	void saveShape(shape shape, int x, int y);
	void deleteShape(shape shape, int x, int y);
	void init();
	void printBoard(int minX, int minY);
	void drawBorder(int minX, int minY);
	bool checkGameOver(shape newShape, int minX, int minY);


};