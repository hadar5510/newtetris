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
	int minX1 = player1.getMinX();
	int minY1 = player1.getMinY();
	player1.board.drawBorder(minX1, minY1);

	int minX2 = player2.getMinX();
	int minY2 = player2.getMinY();
	player2.board.drawBorder(minX2, minY2);

	bool flag1 = player1.getFlag();
	bool flag2 = player2.getFlag();

	player1.board.init();
	player2.board.init();


	player1.board.printBoard(minX1, minY1);
	player2.board.printBoard(minX2, minY2);

	std::srand(static_cast<unsigned int>(std::time(nullptr)));


	shape currshape1;
	shape currshape2;

	currshape1.init(minX1, minY1, std::rand() % 7);
	currshape2.init(minX2, minY2, std::rand() % 7);

	player1.currShape = currshape1;
	player2.currShape = currshape2;


	player1.board.saveShape(currshape1, minX1, minY1);
	player2.board.saveShape(currshape2, minX2, minY2);


	char keyPressed;
	char p1char, p2char;
	int goingDownCounter = 0;

	//THE GAME
	while (flag1 == false && flag2 == false)
	{

		if (_kbhit())
		{

			keyPressed = toupper(_getch());

			p1char = NULL;
			p2char = NULL;

			// buffer workaround
			if (keyPressed == 'A' || keyPressed == 'S' || keyPressed == 'D' || keyPressed == 'W' || keyPressed == 'X') {
				p1char = keyPressed;
				while (_kbhit()) {
					char ch = toupper(_getch());
					if (ch == 'J' || ch == 'L' || ch == 'K' || ch == 'I' || ch == 'M') {
						p2char = ch;
						break;
					}
				}
			}

			if (keyPressed == 'J' || keyPressed == 'L' || keyPressed == 'K' || keyPressed == 'I' || keyPressed == 'M') {
				p2char = keyPressed;
				while (_kbhit()) {
					char ch = toupper(_getch());
					if (ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W' || ch == 'X')
					{
						p1char = ch;
						break;
					}
				}
			}
			while (_kbhit()) 		//clearing input buffer
				char ch = _getch();

			if(p1char != NULL)
				playerTurn(player1, p1char);
			
			if(p2char != NULL)
				playerTurn(player2, p2char);



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

	//winner announce
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
	
	menu.gameMenu(false);		//start new game
	
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
			currPlayer.currShape.move('v');
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
		currPlayer.currShape.move('v');
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