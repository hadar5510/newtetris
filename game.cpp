#include "game.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <cstdlib>
#include <ctime>

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


	player1.board.printBoard(minX1, minY1);
	player2.board.printBoard(minX2, minY2);



	//gotoxy(0, minY1 + GAME_HEIGHT + 5);

	char keyPressed;

	//the game
	while (flag1 == false && flag2 == false)
	{

		if (_kbhit())
		{

			keyPressed = _getch();

			if (keyPressed == 27)		//pausing game
				menu.gameMenu(true);

			bool isLegal = true;

			//add upper/lower func
			//move PLAYER 1
			if (keyPressed == 'a' || keyPressed == 's' || keyPressed == 'd' || keyPressed == 'w' || keyPressed == 'x') {

				isLegal = player1.board.checkShapeMoveLeftRight(player1.currShape, minX1, minY1, keyPressed);

				if (keyPressed == 'x')		//drop
				{
					bool drop = true;

					while (drop)
					{

						player1.board.deleteShape(player1.currShape, minX1, minY1);
						player1.currShape.move('v');
						player1.board.saveShape(player1.currShape, minX1, minY1);
						
						player1.board.printBoard(minX1, minY1);

						drop = player1.board.checkShapeGoDown(player1.currShape, minX1, minY1);
					}


				}

				//go down
				if (isLegal && player1.board.checkShapeGoDown(player1.currShape, minX1, minY1))		
				{
					player1.board.deleteShape(player1.currShape, minX1, minY1);
					player1.currShape.move(keyPressed);
					player1.board.saveShape(player1.currShape, minX1, minY1);
				}

				
				player1.board.printBoard(minX1, minY1);
			}

			//move PLAYER 2
			if (keyPressed == 'j' || keyPressed == 'l' || keyPressed == 'k' || keyPressed == 'i' || keyPressed == 'm') {

				isLegal = player2.board.checkShapeMoveLeftRight(player2.currShape, minX2, minY2, keyPressed);

				if (keyPressed == 'm')
				{
					bool drop = true;

					while (drop)
					{

						player2.board.deleteShape(player2.currShape, minX2, minY2);
						player2.currShape.move('v');
						player2.board.saveShape(player2.currShape, minX2, minY2);

						player2.board.printBoard(minX2, minY2);


						drop = player2.board.checkShapeGoDown(player2.currShape, minX2, minY2);
					}
				}

				//go down
				else if (isLegal && player2.board.checkShapeGoDown(player2.currShape, minX2, minY2))
				{
					player2.board.deleteShape(player2.currShape, minX2, minY2);
					player2.currShape.move(keyPressed);
					player2.board.saveShape(player2.currShape, minX2, minY2);
				}

				
				player2.board.printBoard(minX2, minY2);
			}


		}



		bool goDown1 = true;
		bool goDown2 = true;

		goDown1 = player1.board.checkShapeGoDown(player1.currShape, minX1, minY1);



		//go down always
		if (goDown1)
		{
			player1.board.deleteShape(player1.currShape, minX1, minY1);
			player1.currShape.move('v');
			player1.board.saveShape(player1.currShape, minX1, minY1);
			player1.board.printBoard(minX1, minY1);
		}
		else
		{
			player1.board.checkFullLines();
			player1.board.printBoard(minX1, minY1);
			currshape1.init(minX1, minY1, std::rand() % 7);
			player1.currShape = currshape1;
			flag1 = player1.board.checkGameOver(player1.currShape, minX1, minY1);
			player1.board.saveShape(player1.currShape, minX1, minY1);
			player1.board.printBoard(minX1, minY1);
		}


		goDown2 = player2.board.checkShapeGoDown(player2.currShape, minX2, minY2);

		if (goDown2)
		{
			player2.board.deleteShape(player2.currShape, minX2, minY2);
			player2.currShape.move('v');
			player2.board.saveShape(player2.currShape, minX2, minY2);
			player2.board.printBoard(minX2, minY2);
		}
		else
		{
			player2.board.checkFullLines();
			player2.board.printBoard(minX2, minY2);
			currshape2.init(minX2, minY2, std::rand() % 7);
			player2.currShape = currshape2;
			flag2 = player2.board.checkGameOver(player2.currShape, minX2, minY2);
			player2.board.saveShape(player2.currShape, minX2, minY2);
			player2.board.printBoard(minX2, minY2);
		}


		Sleep(400);


	}



	//winner announce
	system("cls");
	gotoxy(MIN_X + GAME_WIDTH, 2);
	if (flag1)
		cout << "Player 1 LOST,  Player 2 is the WINNER";
	
	else
		cout << "Player 2 LOST,  Player 1 is the WINNER";
	
	gotoxy(MIN_X + GAME_WIDTH, 8);
	cout << "Press any key to go back to menu"; 
	
	if (char t = _getch())
	{
		
		menu.gameMenu(false);
	}
	
	

}