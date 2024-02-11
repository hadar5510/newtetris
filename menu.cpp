#include "menu.h"
#include "game.h"
#include "player.h"
#include "general.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


void Menu::gameMenu(bool isPaused)
{
	char ch;
	bool gameFlag = true;


	while (gameFlag)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

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
			cout << "for game with colors press 1" << endl << "for game without colors press 2";
			char c = _getch();
			
			bool isColoredGame;

			if (c == '1')
				isColoredGame = true;
			else
				isColoredGame = false;

			Player player1(MIN_X, MIN_Y, P1_LEFT, P1_RIGHT, P1_DROP, P1_ROTATE_CLOCK, P1_ROTATE_ANTI_CLOCK, false, isColoredGame);
			Player player2(MIN_X * 2 + GAME_WIDTH, MIN_Y, P2_LEFT, P2_RIGHT, P2_DROP, P2_ROTATE_CLOCK, P2_ROTATE_ANTI_CLOCK, false, isColoredGame);

			Game game;

			system("cls");
			game.run(player1, player2, isColoredGame);
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