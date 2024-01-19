#include "shape.h"


void shape::init(int minX, int minY, int shapetype)
{
	switch (shapetype)
	{
	case 0: //LL


		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = point(minX + GAME_WIDTH / 2 - 1, minY + 2);
		break;
	case 1: //LR



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = point(minX + GAME_WIDTH / 2 + 1, minY + 2);
		break;
	case 2: //T



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = point(minX + GAME_WIDTH / 2 - 1, minY);
		body[3] = point(minX + GAME_WIDTH / 2, minY + 1); //chupchik
		break;
	case 3: //I



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = point(minX + GAME_WIDTH / 2, minY + 3);
		break;
	case 4: //SQ



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = point(minX + GAME_WIDTH / 2 + 1, minY + 1);
		break;
	case 5: //ZL



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2 - 1, minY);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = point(minX + GAME_WIDTH / 2 + 1, minY + 1);
		break;
	case 6: //ZR


		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = point(minX + GAME_WIDTH / 2 - 1, minY + 1);
		break;
	}


}

//player1.init(MIN_X, MIN_Y, 'a', 'd', 'x', 's', 'w', false);
//player2.init(MIN_X * 2 + 12, MIN_Y, 'j', 'l', 'm', 'k', 'i', false);

void shape::move(player& player, char keyPressed)
{
	for (int i = 0; i < 4; i++)		//default going down
	{
		body[i].y = body[i].y + 1;
	}

	switch (keyPressed)
	{
	case 'a':
	case 'j':
		//LEFT
		for (int i = 0; i < 4; i++)		
		{
			body[i].x = body[i].x - 1;
		}
		
		break;
	case 'd':
	case 'l':
		//RIGHT
		for (int i = 0; i < 4; i++)
		{
			body[i].x = body[i].x + 1;
		}
		break;
	case 'x':
	case 'm':
		//DROP
		for (int i = 0; i < 4; i++)
		{
			body[i].y = body[i].y + 1;
		}
		break;
	case 's':
	case 'k':
		//CLOCKWISE
		break;
	case 'w':
	case 'i':
		//ANTICLOCKWISE
		break;
	}
	

}