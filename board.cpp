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


bool board::checkLegalMove(shape shape, int minX, int minY, char ch)
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
