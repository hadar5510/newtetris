#include "tetrisGame.h"
#include "shapes.h"
#include "general.h"
#include "point.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


void tetrisGame::init()
{
	drawBorder();

	//create new shape
	this->shape = Shape('@', GameConfig::COLORS[4], Shape::ShapeType::LL);
}

//void tetrisGame::freeMemory()
//{
//	delete[]allSnakes;
//}

void tetrisGame::run()
{
	while (true)
	{
		int keyPressed = 122;
		if (_kbhit())
		{
			keyPressed = _getch();
			if (keyPressed == (int)GameConfig::eKeys::ESC)
				break;
		}
		Sleep(500);

		this->shape.move((GameConfig::eKeys)keyPressed);
	}
}