#include <iostream>
#include <Windows.h> 
using namespace std;

#include "player.h"


void Player::initBoard()
{
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			boardState[i][j] = false;
		}
	}	
}

void Player::makeMove(GameConfig::eKeys keyPressed)
{
	if(Player::legalMove(keyPressed))
		this->currShape.move(keyPressed);
	else if(keyPressed != GameConfig::eKeys::LEFT && keyPressed != GameConfig::eKeys::RIGHT) {
		this->currShape = Shape('@', GameConfig::COLORS[4], Shape::ShapeType::LL, this->startingX);
	}

}

bool Player::legalMove(GameConfig::eKeys direction)
{
	//stops move to the right when gets to edge
	if (direction == GameConfig::eKeys::LEFT)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->currShape.body[i].x - 1 <= this->startingX)
				return false;
		}
	}
	//stops move to the left when gets to edge
	else if (direction == GameConfig::eKeys::RIGHT)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->currShape.body[i].x + 1 >= this->startingX + GameConfig::GAME_WIDTH + 1)
				return false;
		}
	}

	


	return true;
}
