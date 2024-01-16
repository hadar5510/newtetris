#ifndef __PLAYER_H
#define __PLAYER_H
#include "gameConfig.h"

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

	void initBoard();

};
#endif

