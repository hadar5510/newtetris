#include "game.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void game::run()
{
	player player1, player2;

	player1.init(MIN_X, MIN_Y, 'a', 'd', 'x', 's', 'w', false);
	player2.init(MIN_X * 2 + 12, MIN_Y, 'j', 'l', 'm', 'k', 'i', false);

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




	shape currshape1;
	shape currshape2;

	currshape1.init(minX1, minY1, 0);
	currshape2.init(minX2, minY2, 4);

	player1.currShape = currshape1;
	player2.currShape = currshape2;



	player1.board.saveShape(currshape1, minX1, minY1);
	player2.board.saveShape(currshape2, minX2, minY2);


	player1.board.printBoard(minX1, minY1);
	player2.board.printBoard(minX2, minY2);

	bool legal1, legal2;


	//gotoxy(0, minY1 + GAME_HEIGHT + 5);

	char keyPressed;

	//the game
	while (flag1 == false && flag2 == false)
	{
		if (_kbhit()) 
		{
			keyPressed = _getch();
			
			bool isLegal = false;
		
			//add upper/lower func
			if (keyPressed == 'a'  || keyPressed == 's' || keyPressed == 'd' || keyPressed == 'w' || keyPressed == 'x') {
				
				isLegal = player1.board.checkLegalMove(player1.currShape, minX1, minY1, 0);

				if (isLegal) 
				{
					player1.board.deleteShape(player1.currShape, minX1, minY1);
					player1.currShape.move(player1, keyPressed);
					player1.board.saveShape(player1.currShape, minX1, minY1);
				}

				Sleep(500);
				player1.board.printBoard(minX1, minY1);
			}

			if (keyPressed == 'j' || keyPressed == 'l' || keyPressed == 'k' || keyPressed == 'i' || keyPressed == 'm') {
				
				isLegal = player2.board.checkLegalMove(player2.currShape, minX1, minY1, 0);

				if (isLegal) 
				{
					player2.board.deleteShape(player2.currShape, minX1, minY1);
					player2.currShape.move(player2, keyPressed);
					player2.board.saveShape(player2.currShape, minX1, minY1);
				}

				Sleep(500);
				player2.board.printBoard(minX1, minY1);
			}

			/*legal1 = player1.board.checkLegalMove(player1.currShape, minX1, minY1, 0);


			if (legal1 == true)
			{
				player1.board.deleteShape(player1.currShape, minX1, minY1);
				player1.currShape.move();
				player1.board.saveShape(player1.currShape, minX1, minY1);
			}


			legal2 = player2.board.checkLegalMove(player2.currShape, minX2, minY2, 0);
			if (legal2 == true)
			{

				player2.board.deleteShape(player2.currShape, minX2, minY2);
				player2.currShape.move();
				player2.board.saveShape(player2.currShape, minX2, minY2);
			}

			Sleep(100);

			player1.board.printBoard(minX1, minY1);
			player2.board.printBoard(minX2, minY2);*/
		}

	}








}