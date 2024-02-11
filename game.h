#ifndef __GAME_H
#define __GAME_H

#include "player.h"
#include "general.h"
class menu;


class game
{


public:

	void gameInitialization(player& currPlayer, int& minX, int& minY, bool& flag, shape& currshape);
	void gameturn(player& player1, player& player2, char keyPressed);
	bool isItPlayersKeys(player& currPlayer, char keyPressed);
	void run(player& player1, player& player2);
	void playerTurn(player& currPlayer, char keyPressed);
	void moveShapedown(player& currPlayer, shape currShape, bool& flag);
	void endOfGame(bool flag1);
};



#endif 