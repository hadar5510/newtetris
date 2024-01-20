#include "board.h"
#include <windows.h> // for gotoxy
#include <process.h> // for system
#include <iostream>


using namespace std;


void board::drawBorder(int minX, int minY)
{
	for (int col = minX; col < gameWidth + minX; col++)
	{
		gotoxy(col, minY - 1); //top of the board
		cout << "-";

		gotoxy(col, minY + GAME_HEIGHT); //bottom of the board
		cout << "-";

	}


	for (int row = minY - 1; row <= GAME_HEIGHT + minY; row++)
	{

		gotoxy(minX - 1, row);		//left border
		cout << "|";


		gotoxy(GAME_WIDTH + minX, row); //right border
		cout << "|";

	}
}



void board::printBoard(int minX, int minY)
{
	for (int row = 0; row < gameHeight; row++)
	{

		for (int col = 0; col < gameWidth; col++)
		{
			gotoxy(minX + col, minY + row);
			cout << board[row][col];
		}

	}
}



void board::init()
{
	for (int row = 0; row < gameHeight; row++)
	{

		for (int col = 0; col < gameWidth; col++)
		{

			board[row][col] = ' ';
		}

	}
}



void board::saveShape(shape shape, int x, int y)
{
	int col, row;		//x = minX y = minY

	for (int i = 0; i < 4; i++)
	{
		col = shape.body[i].x - x;
		row = shape.body[i].y - y;

		board[row][col] = '@';
	}
}

void board::deleteShape(shape shape, int x, int y)
{
	int col, row;		//x = minX y = minY

	for (int i = 0; i < 4; i++)
	{
		col = shape.body[i].x - x;
		row = shape.body[i].y - y;

		board[row][col] = ' ';
	}



}


void board::checkFullLines()
{

	int counter = 0;

	for (int i = this->gameHeight - 1; i >= 0; i--)
	{
		counter = 0;

		for (int j = 0; j < this->gameWidth; j++)
		{
			if (board[i][j] != ' ')
			{
				counter++;
			}
			else
			{
				break;
			}
		}

		if (counter == this->gameWidth)
		{
			deleteLine(i);
		}
	}
}


void board::deleteLine(int line)
{

	for (int i = 0; i < this->gameWidth; i++)
	{
		board[line][i] = ' ';
		/*Sleep(70);*/

	}

	int row = line;

	for (row; row > 0; row--)
	{
		for (int col = 0; col < this->gameWidth; col++)
		{
			board[row][col] = board[row - 1][col];
		}
	}


	for (int j = 0; j < this->gameWidth; j++)
	{
		board[0][j] = ' ';
	}



}


bool board::checkShapeGoDown(shape shape, int minX, int minY)
{
	bool legal = true;

	for (int i = 0; i < 4; i++)
	{
		int col = shape.body[i].x - minX;
		int row = shape.body[i].y - minY;

		// Check if we are not already at the bottom
		if (row < minY + this->gameHeight - 1)
		{
			// Check if the square below is not empty
			if (board[row + 1][col] != ' ')
			{
				int counter = 0;
				// Check if the square below is not himself
				for (int j = 0; j < 4; j++)
				{
					int colC = shape.body[j].x - minX;
					int rowC = shape.body[j].y - minY;

					if (row + 1 == rowC && col == colC)
					{
						counter++;
					}
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


//
//int board::checkDrop(shape shape, int minX, int minY)
//{
//	bool down = true;
//
//
//
//
//
//
//
//}
//



bool board::checkShapeMoveLeftRight(shape shape, int minX, int minY, char direction)
{

	bool legal = true;

	if (direction == 'a' || direction == 'j') //LEFT
	{
		for (int i = 0; i < 4; i++)
		{
			int col = shape.body[i].x - minX;
			int row = shape.body[i].y - minY;

			/*cout << col;*/

			if (col == 0)
			{
				legal = false;
				break;
			}
			else
			{
				// Check if the square to the left is not empty
				if (board[row][col - 1] != ' ')
				{
					int counter = 0;
					// Check if the square to the left is not himself
					for (int j = 0; j < 4; j++)
					{
						int colC = shape.body[j].x - minX;
						int rowC = shape.body[j].y - minY;

						if (row == rowC && col - 1 == colC)
						{
							counter++;
						}
					}

					if (counter == 0)
					{
						legal = false;
						break;
					}
				}


			}




		}

	}



	else
	{										//check move to the right

		for (int i = 0; i < 4; i++)
		{
			int col = shape.body[i].x - minX;
			int row = shape.body[i].y - minY;


			if (col == gameWidth - 1)
			{
				legal = false;
				break;
			}
			else
			{
				// Check if the square to the right is not empty
				if (board[row][col + 1] != ' ')
				{
					int counter = 0;
					// Check if the square to the right is not himself
					for (int j = 0; j < 4; j++)
					{
						int colC = shape.body[j].x - minX;
						int rowC = shape.body[j].y - minY;

						if (row == rowC && col + 1 == colC)
						{
							counter++;
						}
					}

					if (counter == 0)
					{
						legal = false;
						break;
					}
				}

			}



		}

	}
	return legal;

}




bool board::checkGameOver(shape newShape, int minX, int minY)
{
	bool gameOver = false;

	int col, row;		//x = minX y = minY

	for (int i = 0; i < 4; i++)
	{
		col = newShape.body[i].x - minX;
		row = newShape.body[i].y - minY;

		if (board[row][col] != ' ')
		{
			gameOver = true;
			break;
		}
	}

	return gameOver;



}