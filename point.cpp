#include "point.h"
#include "general.h"

#include <iostream>
#include <Windows.h>
using namespace std;


void point::init(int x, int y)
{
	this->x = x;
	this->y = y;
	diff_x = 1;
	diff_y = 0;
}


void point::draw(char ch, int backcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backcolor);
	gotoxy(x + MIN_X - 1, y + MIN_Y - 1);
	cout << ch;
}
