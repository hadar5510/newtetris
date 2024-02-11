#ifndef __BOARD_H
#define __BOARD_H
#include "shape.h"
#include "general.h"
#include "boardCell.h"

class Board
{
private:
	int minX, minY;
	bool isColoredGame;
	static constexpr int gameWidth = GAME_WIDTH;		//fixed board size
	static constexpr int gameHeight = GAME_HEIGHT;
	BoardCell board[gameHeight][gameWidth];

	void deleteLine(int line);

public:
	Board() = default;
	Board(int minX, int minY, bool isColoredGame);


	void checkFullLines();
	bool checkShapeMoveLeftRight(Shape& shape, char direction);
	bool checkShapeRotate(Shape& currshape, char direction) const;
	bool checkShapeGoDown(Shape& shape) ;
	void saveShape(Shape& shape);
	void deleteShape(Shape& shape);
	void printBoard() ;
	void drawBorder() const;
	bool checkGameOver(Shape& newShape) ;


};

#endif