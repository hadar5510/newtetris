#ifndef __GAME_H
#define __GAME_H

#include "player.h"
#include "general.h"
class Menu;


class Game
{
private:

	

public:


	void gameInitialization(Player& currPlayer, bool& flag, Shape& currshape) const;
	void gameturn(Player& player1, Player& player2, char keyPressed) const;
	bool isItPlayersKeys(Player& currPlayer, char keyPressed) const;
	void run(Player& player1, Player& player2, bool isColoredGame) const;
	void playerTurn(Player& currPlayer, char keyPressed) const;
	void moveShapedown(Player& currPlayer, Shape currShape, bool& flag) const;
	void endOfGame(bool flag1) const;
};



#endif 