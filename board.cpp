#include "board.h"
#include <windows.h> 
#include <process.h> 
#include <iostream>


using namespace std;


Board::Board(int minX, int minY, bool isColoredGame)
{
	this->minX = minX;
	this->minY = minY;
	this->isColoredGame = isColoredGame;

	for (int row = 0; row < gameHeight; row++)
	{
		for (int col = 0; col < gameWidth; col++)
			board[row][col].setSymbol(' ');
	}
}






//drwaing the fixed borders of the board
void Board::drawBorder() const
{
	for (int col = minX; col < gameWidth + minX; col++)
	{
		gotoxy(col, minY - 1);					//top of the board
		cout << "-";
		gotoxy(col, minY + GAME_HEIGHT);		//bottom of the board
		cout << "-";
	}

	for (int row = minY - 1; row <= GAME_HEIGHT + minY; row++)
	{
		gotoxy(minX - 1, row);				//left border
		cout << "|";
		gotoxy(GAME_WIDTH + minX, row);		//right border
		cout << "|";
	}
}


void Board::printBoard() 
{
	for (int row = 0; row < gameHeight; row++)
	{
		for (int col = 0; col < gameWidth; col++)
		{
			gotoxy(minX + col, minY + row);
			if (this->board[row][col].getSymbol() != ' ')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board[row][col].getColor());
				cout << board[row][col].getSymbol();
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << " ";
			}


		}

	}
}



//saves the new shape to the board
void Board::saveShape(Shape& shape)
{
	int col, row;		//x = minX y = minY

	for (int i = 0; i < 4; i++)
	{
		col = shape.body[i].x - minX;
		row = shape.body[i].y - minY;

		board[row][col].setSymbol('@');
		if(this->isColoredGame)
			board[row][col].setColor(shape.getColor()); 

	}
}


void Board::deleteShape(Shape& shape)
{
	int col, row;		//x = minX y = minY

	for (int i = 0; i < 4; i++)
	{
		col = shape.body[i].x - minX;
		row = shape.body[i].y - minY;

		board[row][col].setSymbol(' ');
	}
}

//this function checks and deletes the full lines
void Board::checkFullLines()
{
	int counter = 0;

	for (int i = this->gameHeight - 1; i >= 0; i--)
	{
		counter = 0;

		for (int j = 0; j < this->gameWidth; j++)
		{
			if (board[i][j].getSymbol() != ' ')			//change
				counter++;
			else
				break;
		}

		if (counter == this->gameWidth)
			deleteLine(i);

	}
}


void Board::deleteLine(int line)
{

	for (int i = 0; i < this->gameWidth; i++)
		board[line][i].setSymbol(' ');

	int row = line;

	for (row; row > 0; row--)
	{
		for (int col = 0; col < this->gameWidth; col++)
			board[row][col] = board[row - 1][col];

	}

	for (int j = 0; j < this->gameWidth; j++)
		board[0][j].setSymbol(' ');
}





//check if the shape can go down
bool Board::checkShapeGoDown(Shape& shape) 
{
	bool legal = true;

	for (int i = 0; i < 4; i++)
	{
		int col = shape.body[i].x - minX;
		int row = shape.body[i].y - minY;

		//check if we are not already at the bottom
		if (row < minY + this->gameHeight - 1)
		{
			//check if the square below is not empty
			if (board[row + 1][col].getSymbol() != ' ')
			{
				int counter = 0;
				//check if the square below is not himself
				for (int j = 0; j < 4; j++)
				{
					int colC = shape.body[j].x - minX;
					int rowC = shape.body[j].y - minY;

					if (row + 1 == rowC && col == colC)
						counter++;

				}

				if (counter == 0)
				{
					legal = false;
					break;
				}
			}
		}
	}

	return legal;

}


//check if shape can rotate
bool Board::checkShapeRotate(Shape& currshape, char direction) const
{
	bool legal = true;
	Shape tempShape;

	int shapeType = currshape.getShapeType();
	char shapeDirection = currshape.getShapeDirection();

	tempShape.init(minX, minY, shapeType);
	tempShape.setShapeDirection(shapeDirection);

	for (int i = 0; i < 4; i++)
	{
		tempShape.body[i] = currshape.body[i];
	}
	tempShape.move(direction);


	for (int i = 0; i < 4; i++)
	{
		int col = tempShape.body[i].x - minX;
		int row = tempShape.body[i].y - minY;

		if (col <= -1 || col >= gameWidth || row <= 0)
		{
			legal = false;
		}

	}

	return legal;

}




//check if the shape can move left or right
bool Board::checkShapeMoveLeftRight(Shape& shape, char direction) 
{

	int directionChange;


	if (direction == P1_LEFT || direction == P2_LEFT)
		directionChange = -1;
	else
		directionChange = 1;


	for (int i = 0; i < 4; ++i)
	{
		int col = shape.body[i].x - minX;
		int row = shape.body[i].y - minY;

		//check if the move is within the boundaries of the board
		if (col + directionChange < 0 || col + directionChange >= gameWidth)
			return false;


		//check if the square to the left or right is not empty
		if (board[row][col + directionChange].getSymbol() != ' ')
		{
			//check if the square to the left or right is not part of the shape
			bool isPartOfShape = false;
			for (int j = 0; j < 4; ++j) {
				int colC = shape.body[j].x - minX;
				int rowC = shape.body[j].y - minY;

				if (row == rowC && col + directionChange == colC)
				{
					isPartOfShape = true;
					break;
				}
			}

			if (!isPartOfShape)
				return false;

		}
	}


	return true;
}





bool Board::checkGameOver(Shape& newShape) 
{
	bool gameOver = false;
	int col, row;
	//if the new shape cant go in to the board - game is over
	for (int i = 0; i < 4; i++)
	{
		col = newShape.body[i].x - minX;
		row = newShape.body[i].y - minY;

		if (board[row][col].getSymbol() != ' ')
		{
			gameOver = true;
			break;
		}
	}
	return gameOver;
}