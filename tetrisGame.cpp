#include "tetrisGame.h"
#include "shapes.h"
#include "general.h"
#include "point.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;



void tetrisGame::init(int num)
{
	drawBorder();

	numOfSnakes = num;
	allSnakes = new shapes[numOfSnakes];
	for (int i = 0; i < numOfSnakes; i++)
	{
		Point head;
		/*head.init(rand() % GameConfig::GAME_WIDTH, rand() % GameConfig::GAME_HEIGHT);*/
		head.init((GameConfig::GAME_WIDTH / 2), -1);
		allSnakes[i].init(head, '#', GameConfig::COLORS[(i % (GameConfig::NUM_OF_COLORS - 1)) + 1]);
	}
}
void tetrisGame::freeMemory()
{
	delete[]allSnakes;
}





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
		for (int i = 0; i < numOfSnakes; i++)
			allSnakes[i].move((GameConfig::eKeys)keyPressed);
	}
}

