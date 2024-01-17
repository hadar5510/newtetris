#include "tetrisGame.h"
#include "shapes.h"
#include "general.h"
#include "point.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "player.h"
using namespace std;


void tetrisGame::init()
{
	drawBorder();

	//create new shape
	//this->shape = Shape('@', GameConfig::COLORS[4], Shape::ShapeType::LL);
}

//void tetrisGame::freeMemory()
//{
//	delete[]allSnakes;
//}

void tetrisGame::run()
{
	int playerOneOffset = GameConfig::MIN_X;
	int playerTwoOffset = playerOneOffset + GameConfig::MIN_X + GameConfig::GAME_WIDTH;
	Player p1(playerOneOffset);
	Player p2(playerTwoOffset);
	p1.currShape = Shape('@', GameConfig::COLORS[4], Shape::ShapeType::LL, playerOneOffset);
	p2.currShape = Shape('@', GameConfig::COLORS[5], Shape::ShapeType::LL, playerTwoOffset);

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
		p1.makeMove((GameConfig::eKeys)keyPressed);
		p2.makeMove((GameConfig::eKeys)keyPressed);

		
	}
}