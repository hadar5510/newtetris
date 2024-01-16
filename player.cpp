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
