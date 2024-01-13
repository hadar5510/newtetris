#include <windows.h> // for gotoxy
#include <process.h> // for system
#include <iostream>
#include "general.h"
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}



void clrscr()
{
	system("cls");
}




void drawBorder()
{
	for (int col = GameConfig::MIN_X; col < GameConfig::GAME_WIDTH + GameConfig::MIN_X; col++)
	{
		gotoxy(col, GameConfig::MIN_Y - 1);
		cout << "-";

		gotoxy(col + GameConfig::GAME_WIDTH + GameConfig::MIN_X, GameConfig::MIN_Y - 1);
		cout << "-";

		gotoxy(col, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y);
		cout << "-";

		gotoxy(col + GameConfig::GAME_WIDTH + GameConfig::MIN_X, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y);
		cout << "-";
	}


	for (int row = GameConfig::MIN_Y - 1; row <= GameConfig::GAME_HEIGHT + GameConfig::MIN_Y; row++)
	{

		//left line of 2 boards
		gotoxy(GameConfig::MIN_X - 1, row);
		cout << "|";

		gotoxy(GameConfig::MIN_X + GameConfig::MIN_X + GameConfig::GAME_WIDTH - 1, row);
		cout << "|";

		//right line of 2 boards
		gotoxy(GameConfig::GAME_WIDTH + GameConfig::MIN_X, row);
		cout << "|";

		gotoxy(GameConfig::MIN_X + GameConfig::MIN_X + GameConfig::GAME_WIDTH + GameConfig::GAME_WIDTH, row);
		cout << "|";
	}
}

//char getCharAtPosition(int x, int y) {
//	// Get the handle to the console screen buffer
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// Set up the COORD structure with the desired position
//	COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
//
//	// Variable to store the character read
//	char ch;
//
//	// Read the character from the console screen buffer
//	if (ReadConsoleOutputCharacterA(hConsole, &ch, 1, coord, nullptr)) {
//		return ch;
//	}
//	else {
//		// Error handling (you can customize this part based on your needs)
//		std::cerr << "Error reading character at position (" << x << ", " << y << ")" << std::endl;
//		return '\0';  // Return a null character in case of an error
//	}
//}
