#include "general.h"


#include <windows.h> // for gotoxy
#include <process.h> // for system
#include <iostream>

using namespace std;

//go to x y on cmd that are given
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

//clears the screen of everything written on it
void clrscr()
{
	system("cls");
}