#ifndef __PLAYER_H
#define __PLAYER_H
#include "gameConfig.h"
#include "shapes.h"

class Player
{
	int boardState[18][12];
	//keys?
	int startingX;
	int startingY = GameConfig::MIN_Y;

public:

	Player(int x) //middle point of each playerboard
	{
		startingX = x;
	};

	Shape currShape;

	void initBoard();
	void makeMove(GameConfig::eKeys keyPressed);
	bool legalMove(GameConfig::eKeys direction);
};
#endif

