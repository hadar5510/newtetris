#include "menu.h"
#include "game.h"
#include "player.h"
#include "general.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


void menu::gameMenu(bool isPaused)
{
	player player1, player2;
	game game;
	char ch;
	bool gameFlag = true;


	while (gameFlag)
	{
		system("cls");


		gotoxy(50, 0);
		cout << "TETRIS GAME :)" << endl << endl;

		cout << "game rules: " << endl << endl << endl << "(1) - start new game" << endl << endl << "(8) - Present instructions and keys" << endl << endl << "(9) -  EXIT" << endl;


		if (isPaused)
			cout << endl << "(2) - Continue a paused game" << endl;


		ch = _getch();

		if (ch == '2')		//continue paused game
		{
			system("cls");
			return;
		}


		if (ch == '1')		//start new game
		{
			system("cls");
			player1.init(MIN_X, MIN_Y, 'A', 'D', 'X', 'S', 'W', false);
			player2.init(MIN_X * 2 + 12, MIN_Y, 'J', 'L', 'M', 'K', 'I', false);

			game.run(player1, player2);
		}



		if (ch == '8')		//Present instructions and keys
		{
			system("cls");
			cout << "INSTRUCTIONS: " << endl << endl;
			cout << "LEFT PLAYER:  " << endl << "Move left - a/A" << endl << "Move right - d/D" << endl << "ROTATE clockwise - s/S" << endl << "ROTATE counterclockwise - w/W" << endl << "Drop - x/X" << endl << endl;
			cout << "LEFT PLAYER:  " << endl << "Move left - j/J" << endl << "Move right - l/L" << endl << "ROTATE clockwise - k/K" << endl << "ROTATE counterclockwise - i/I" << endl << "Drop - m/M" << endl << endl;

			cout << " - Press anything to go back to menu -" << endl << endl;
			ch = _getch();

		}

		if (ch == '9')		//EXIT
		{
			gameFlag = false;
		}
	}

}