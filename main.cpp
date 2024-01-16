#include <conio.h> // for kbhit+getch
#include <iostream>
#include <stdbool.h>
#include <Windows.h> // for Sleep and colors
using namespace std;

#include "general.h"
#include "gameConfig.h"
#include "point.h"
#include "shapes.h"
#include "tetrisGame.h"
#include "player.h"

void tetrisRun();


int main()
{
	tetrisRun();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[0]);
	gotoxy(0, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y + 2);
}


void tetrisRun()
{
	tetrisGame theGame;
	Player(GameConfig::MIN_X + GameConfig::GAME_WIDTH / 2);

	theGame.init();
	theGame.run();
	//theGame.freeMemory();
}