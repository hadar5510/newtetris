#ifndef __BOARD_H
#define __BOARD_H
#include "shape.h"
#include "general.h"


class board
{
public:
	static constexpr int gameWidth = 12;		//fixed board size
	static constexpr int gameHeight = 18;
	char board[gameHeight][gameWidth];



	void checkFullLines();
	void deleteLine(int line);
	bool checkShapeMoveLeftRight(shape shape, int minX, int minY, char direction);
	bool checkShapeRotate(shape shape, int minX, int minY, char direction);
	bool checkShapeGoDown(shape shape, int minX, int minY);
	void saveShape(shape shape, int x, int y);
	void deleteShape(shape shape, int x, int y);
	void init();
	void printBoard(int minX, int minY);
	void drawBorder(int minX, int minY);
	bool checkGameOver(shape newShape, int minX, int minY);


};

#endif