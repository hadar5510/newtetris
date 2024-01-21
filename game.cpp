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


void game::run(player& player1, player& player2)
{
	menu menu;

	char keyPressed;
	int minX1, minY1, minX2, minY2, goingDownCounter = 0;
	bool flag1, flag2;
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
			

			if (keyPressed == 27)		//pausing game
			{
				menu.gameMenu(true);
				player1.board.drawBorder(minX1, minY1);
				player2.board.drawBorder(minX2, minY2);
			}
			

		}
		
		if (goingDownCounter == 0) {
			moveShapedown(player1, currshape1, flag1);

			moveShapedown(player2, currshape1, flag2);
		}

		goingDownCounter = (goingDownCounter + 1) % 20;		//going down every  seconds
	

		Sleep(17);
	
	}

	//WINNER ANNOUNCEMENT
	endOfGame(flag1);

	menu.gameMenu(false);		//start new game
}
	
//initializing players and drawing boards
void game::gameInitialization(player& currPlayer, int& minX, int& minY, bool& flag, shape& currshape)
{
	minX = currPlayer.getMinX();
	minY = currPlayer.getMinY();
	currPlayer.board.drawBorder(minX, minY);


	flag = currPlayer.getFlag();


	currPlayer.board.init();
	currPlayer.board.init();


	std::srand(static_cast<unsigned int>(std::time(nullptr)));


	

	currshape.init(minX, minY, std::rand() % 7);
	

	currPlayer.currShape = currshape;
	

	currPlayer.board.saveShape(currshape, minX, minY);


}


void game::gameturn(player& player1, player& player2,char keyPressed)
{
	
	char p1char = NULL;
	char p2char = NULL;

	// buffer workaround
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
	while (_kbhit()) 		//clearing input buffer
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


void game::playerTurn(player& currPlayer, char keyPressed)
{
	bool isLegal = true;
	int minX = currPlayer.getMinX();
	int minY = currPlayer.getMinY();


	isLegal = currPlayer.board.checkShapeMoveLeftRight(currPlayer.currShape, minX, minY, keyPressed);

	char dropkey = currPlayer.getDrop();		//amount player can drop shape

	if (keyPressed == dropkey)		//drop
	{
		bool drop = true;

		while (drop)
		{

			currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
			currPlayer.currShape.move(DOWN);
			currPlayer.board.saveShape(currPlayer.currShape, minX, minY);

			currPlayer.board.printBoard(minX, minY);

			drop = currPlayer.board.checkShapeGoDown(currPlayer.currShape, minX, minY);
		}

	}

	//go down
	if (isLegal && currPlayer.board.checkShapeGoDown(currPlayer.currShape, minX, minY))
	{
		currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
		currPlayer.currShape.move(keyPressed);
		currPlayer.board.saveShape(currPlayer.currShape, minX, minY);
	}


	currPlayer.board.printBoard(minX, minY);
	

}

//moves the player who was sent current shape down by one block
void game::moveShapedown(player& currPlayer, shape currShape, bool& flag)
{
	int minX = currPlayer.getMinX();
	int minY = currPlayer.getMinY();
	bool goDown = true;

	goDown = currPlayer.board.checkShapeGoDown(currPlayer.currShape, minX, minY);


	//go down always
	if (goDown)
	{
		currPlayer.board.deleteShape(currPlayer.currShape, minX, minY);
		currPlayer.currShape.move(DOWN);
		currPlayer.board.saveShape(currPlayer.currShape, minX, minY);
		currPlayer.board.printBoard(minX, minY);
	}
	else
	{
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