#include "game.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "menu.h"


using namespace std;

//plays the game

void game::run(player& player1, player& player2)
{
	//initializing game variables
	menu menu;
	char keyPressed;
	int minX1, minY1, minX2, minY2, goingDownCounter = 0;
	bool flag1, flag2;						//flag checks if player won
	shape currshape1, currshape2;

	gameInitialization(player1, minX1, minY1, flag1, currshape1);

	gameInitialization(player2, minX2, minY2, flag2, currshape2);

	//THE GAME
	while (flag1 == false && flag2 == false)
	{
		if (_kbhit())
		{
			keyPressed = toupper(_getch());

			gameturn(player1, player2, keyPressed);

			if (keyPressed == ESC)						//pausing game
			{
				menu.gameMenu(true);
				player1.board.drawBorder(minX1, minY1);		//if the game is resumed drawing borders again
				player2.board.drawBorder(minX2, minY2);
			}
		}


		if (goingDownCounter == 0)
		{
			moveShapedown(player1, currshape1, flag1);		//synchronizing shape going down and moving to be smooth ingame
			moveShapedown(player2, currshape1, flag2);
		}

		goingDownCounter = (goingDownCounter + 1) % 20;

		Sleep(17);
	}

	//winner announcement
	endOfGame(flag1);

	menu.gameMenu(false);						//open menu
}





//initializing players and drawing boards
void game::gameInitialization(player& currPlayer, int& minX, int& minY, bool& flag, shape& currshape)
{
	//drawing player border according to minX minY
	minX = currPlayer.getMinX();
	minY = currPlayer.getMinY();
	currPlayer.board.drawBorder(minX, minY);

	flag = currPlayer.getFlag();

	currPlayer.board.init();							//initializes board and shape (random from 7 shapes)
	currPlayer.board.init();

	currshape.init(minX, minY, std::rand() % 7);
	currPlayer.currShape = currshape;

	currPlayer.board.saveShape(currshape, minX, minY);
}


//a key was pressed - this function plays the turn accordingly
void game::gameturn(player& player1, player& player2, char keyPressed)
{
	char p1char = NULL;
	char p2char = NULL;

	//buffer workaround
	if (isItPlayersKeys(player1, keyPressed))
	{
		p1char = keyPressed;
		while (_kbhit())
		{
			char ch = toupper(_getch());
			if (isItPlayersKeys(player2, keyPressed))
			{
				p2char = ch;
				break;
			}
		}
	}

	if (isItPlayersKeys(player2, keyPressed))
	{
		p2char = keyPressed;
		while (_kbhit()) {
			char ch = toupper(_getch());
			if (isItPlayersKeys(player1, keyPressed))
			{
				p1char = ch;
				break;
			}
		}
	}
	while (_kbhit()) 				//clearing input buffer
		char ch = _getch();

	if (p1char != NULL)
		playerTurn(player1, p1char);
	if (p2char != NULL)
		playerTurn(player2, p2char);
}



//returns if the keypressed is of the player that has been sent
bool game::isItPlayersKeys(player& currPlayer, char keyPressed)
{
	if (keyPressed == currPlayer.getLeft() || keyPressed == currPlayer.getRight() || keyPressed == currPlayer.getRotateClock() || keyPressed == currPlayer.getRotateAntiClock() || keyPressed == currPlayer.getDrop())
		return true;
	return false;
}



//the function play the players turn
void game::playerTurn(player& currPlayer, char keyPressed)
{
	bool isLegal = true;
	bool rotateLegal = true;
	int minX = currPlayer.getMinX();
	int minY = currPlayer.getMinY();

	//check if the move is legal
	isLegal = currPlayer.board.checkShapeMoveLeftRight(currPlayer.currShape, minX, minY, keyPressed);


	char dropkey = currPlayer.getDrop();

	if (keyPressed == dropkey)		//if drop was pressed, check if can move down and loop until cannot move down
	{
		bool drop = true;
		drop = currPlayer.board.checkShapeGoDown(currPlayer.currShape, minX, minY);

		while (drop)
		{
			currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
			currPlayer.currShape.move(DOWN);
			currPlayer.board.saveShape(currPlayer.currShape, minX, minY);

			currPlayer.board.printBoard(minX, minY);

			drop = currPlayer.board.checkShapeGoDown(currPlayer.currShape, minX, minY);
		}
	}

	char rotateKey1 = currPlayer.getRotateClock();
	char rotateKey2 = currPlayer.getRotateAntiClock();

	if (keyPressed == rotateKey1 || keyPressed == rotateKey2)
	{

		rotateLegal = currPlayer.board.checkShapeRotate(currPlayer.currShape, minX, minY, keyPressed);
	}

																		//check if can rotate shape
	/*if (keyPressed == rotateKey1 || keyPressed == rotateKey2)
	{
		rotateLegal = currPlayer.board.checkShapeRotate(currPlayer.currShape, minX, minY, keyPressed);
		currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
		currPlayer.currShape.move(keyPressed);
		rotateLegal = currPlayer.board.checkShapeRotate(currPlayer.currShape, minX, minY, keyPressed);

		if (rotateLegal)
		{
			currPlayer.board.saveShape(currPlayer.currShape, minX, minY);
		}
		else
		{
			if (keyPressed == rotateKey1)
			{
				currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
				currPlayer.currShape.move(rotateKey2);
				currPlayer.board.saveShape(currPlayer.currShape, minX, minY);
			}
			else
			{
				currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
				currPlayer.currShape.move(rotateKey1);
				currPlayer.board.saveShape(currPlayer.currShape, minX, minY);
			}
		}

	}*/



	//if the move is legal, and shape is not down then play the move
	if (isLegal && currPlayer.board.checkShapeGoDown(currPlayer.currShape, minX, minY) && rotateLegal)
	{
		currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
		currPlayer.currShape.move(keyPressed);
		currPlayer.board.saveShape(currPlayer.currShape, minX, minY);
	}


	currPlayer.board.printBoard(minX, minY);
}


//moves the player's current shape down by one block
void game::moveShapedown(player& currPlayer, shape currShape, bool& flag)
{
	int minX = currPlayer.getMinX();
	int minY = currPlayer.getMinY();
	bool goDown = true;

	//check if shape can go down
	goDown = currPlayer.board.checkShapeGoDown(currPlayer.currShape, minX, minY);


	if (goDown)
	{
		currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
		currPlayer.currShape.move(DOWN);
		currPlayer.board.saveShape(currPlayer.currShape, minX, minY);
		currPlayer.board.printBoard(minX, minY);
	}
	else
	{												//the turn ended - checking full lines to delete, and check if game over
		currPlayer.board.checkFullLines();
		currPlayer.board.printBoard(minX, minY);
		currShape.init(minX, minY, std::rand() % 7);
		currPlayer.currShape = currShape;
		flag = currPlayer.board.checkGameOver(currPlayer.currShape, minX, minY);
		currPlayer.board.saveShape(currPlayer.currShape, minX, minY);
		currPlayer.board.printBoard(minX, minY);
	}
}


//declare player that won and lost and gives option to go back to menu
void game::endOfGame(bool flag1)
{
	system("cls");
	gotoxy(MIN_X + GAME_WIDTH, 2);
	if (flag1)
		cout << "Player 1 LOST,  Player 2 is the WINNER";

	else
		cout << "Player 2 LOST,  Player 1 is the WINNER";


	Sleep(1000);
	gotoxy(MIN_X + GAME_WIDTH, 8);
	cout << "Press any key to go back to menu";

	while (_kbhit()) 		//clearing input buffer
		char ch = _getch();

	char t = _getch();

}