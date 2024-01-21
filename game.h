#pragma once

#include "player.h"
#include "general.h"
class menu;

class game
{
	

public:

	void run(player &player1, player&player2); 
	void playerTurn(player &currPlayer, char keyPressed);
	void moveShapedown(player& currPlayer, shape currShape, bool&flag);
};


