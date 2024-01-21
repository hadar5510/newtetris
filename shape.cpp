#include "shape.h"
#define DOWN v


void shape::init(int minX, int minY, int shapetype)
{
	this->type = shapetype;
	this->shapeDirection = 'N';

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

void shape::move(char keyPressed)
{


	if (keyPressed == 'v')
	{
		for (int i = 0; i < 4; i++)		//default going down
		{
			body[i].y = body[i].y + 1;
		}
	}



	switch (keyPressed)
	{
	case 'A':
	case 'J':
		//LEFT
		for (int i = 0; i < 4; i++)
		{
			body[i].x = body[i].x - 1;
		}

		break;
	case 'D':
	case 'L':
		//RIGHT
		for (int i = 0; i < 4; i++)
		{
			body[i].x = body[i].x + 1;
		}
		break;
	case 'X':
	case 'M':
		//DROP
		for (int i = 0; i < 4; i++)
		{
			body[i].y = body[i].y + 1;
		}
		break;
	case 'S':
	case 'K':
		//CLOCKWISE
		rotate(1);

		break;
	case 'W':
	case 'I':
		//ANTICLOCKWISE

		rotate(2);

		break;
	}


}




void shape::rotate(int direction)
{

	if (direction == 1)
	{

		switch (this->type)
		{
		case 0: //LL

			if (this->shapeDirection == 'N')
			{

				body[2].x += 1; body[2].y -= 1;
				body[3].x += 3; body[3].y -= 1;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{

				body[1].x -= 1; body[1].y -= 1;
				body[2].x -= 2;
				body[3].x -= 3; body[3].y += 1;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{

				body[1].x += 1; body[1].y -= 1;
				body[2].y -= 2;
				body[3].x -= 1; body[3].y -= 3;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{

				body[1].y += 2;
				body[2].x += 1; body[2].y += 3;
				body[3].x += 1; body[3].y += 3;
				this->shapeDirection = 'N';
				break;
			}

			break;
		case 1: //LR

			if (this->shapeDirection == 'N')
			{

				body[2].x += 1; body[2].y -= 2;
				body[3].x += 1; body[3].y -= 2;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{

				body[1].x += 1; body[1].y -= 1;
				body[2].y += 1;
				body[3].x -= 1; body[3].y += 2;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{

				body[1].x -= 1; body[1].y += 1;
				body[2].x -= 2;
				body[3].x -= 3; body[3].y -= 1;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{

				body[2].x += 1; body[2].y += 1;
				body[3].x += 3; body[3].y += 1;
				this->shapeDirection = 'N';
				break;
			}
			break;
		case 2: //T


			if (this->shapeDirection == 'N')
			{

				body[1].x -= 1; body[1].y -= 1;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[3].x += 1; body[3].y -= 1;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{
				body[2].x += 1; body[2].y += 1;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[1].x += 1; body[1].y += 1;
				body[2].x -= 1; body[2].y -= 1;
				body[3].x -= 1; body[3].y += 1;
				this->shapeDirection = 'N';
				break;
			}
			break;
		case 3: //I

			if (this->shapeDirection == 'N')
			{

				body[1].x -= 1; body[1].y -= 1;
				body[2].x -= 2; body[2].y -= 2;
				body[3].x += 1; body[3].y -= 3;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[1].x += 1; body[1].y += 1;
				body[2].x += 2; body[2].y += 2;
				body[3].x -= 1; body[3].y += 3;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{
				body[1].x -= 1; body[1].y -= 1;
				body[2].x -= 2; body[2].y -= 2;
				body[3].x += 1; body[3].y -= 3;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[1].x += 1; body[1].y += 1;
				body[2].x += 2; body[2].y += 2;
				body[3].x -= 1; body[3].y += 3;
				this->shapeDirection = 'N';
				break;
			}
			break;
		case 4: //SQ
			//square is the same
			break;
		case 5: //ZL
			if (this->shapeDirection == 'N')
			{

				body[1].y += 1;
				body[3].x -= 2; body[3].y += 1;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[1].y -= 1;
				body[3].x += 2; body[3].y -= 1;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{

				body[1].y += 1;
				body[3].x -= 2; body[3].y += 1;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[1].y -= 1;
				body[3].x += 2; body[3].y -= 1;
				this->shapeDirection = 'N';
				break;
			}
			break;
		case 6: //ZR

			if (this->shapeDirection == 'N')
			{

				body[1].y += 1;
				body[3].x += 2; body[3].y += 1;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[1].y -= 1;
				body[3].x -= 2; body[3].y -= 1;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{

				body[1].y += 1;
				body[3].x += 2; body[3].y += 1;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[1].y -= 1;
				body[3].x -= 2; body[3].y -= 1;
				this->shapeDirection = 'N';
				break;
			}
			break;
		}



	}




	if (direction == 2)
	{

		switch (this->type)
		{
		case 0: //LL

			if (this->shapeDirection == 'N')
			{

				body[1].y -= 2;
				body[2].x -= 1; body[2].y -= 3;
				body[3].x -= 1; body[3].y -= 3;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{

				body[1].x -= 1; body[1].y += 1;
				body[2].y += 2;
				body[3].x += 1; body[3].y += 3;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{

				body[1].x += 1; body[1].y += 1;
				body[2].x += 2;
				body[3].x += 3; body[3].y -= 1;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{

				body[2].x -= 1; body[2].y += 1;
				body[3].x -= 3; body[3].y += 1;
				this->shapeDirection = 'N';
				break;
			}

			break;
		case 1: //LR

			if (this->shapeDirection == 'N')
			{
				body[2].x -= 1; body[2].y -= 1;
				body[3].x -= 3; body[3].y -= 1;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[1].x += 1; body[1].y -= 1;
				body[2].x += 2;
				body[3].x += 3; body[3].y += 1;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{


				body[1].x -= 1; body[1].y += 1;
				body[2].y -= 1;
				body[3].x += 1; body[3].y -= 2;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[2].x -= 1; body[2].y += 2;
				body[3].x -= 1; body[3].y += 2;
				this->shapeDirection = 'N';
				break;
			}
			break;
		case 2: //T


			if (this->shapeDirection == 'N')
			{

				body[1].x -= 1; body[1].y -= 1;
				body[2].x += 1; body[2].y += 1;
				body[3].x += 1; body[3].y -= 1;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[2].x -= 1; body[2].y -= 1;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{
				body[3].x -= 1; body[3].y += 1;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[1].x += 1; body[1].y += 1;
				this->shapeDirection = 'N';
				break;
			}
			break;
		case 3: //I

			if (this->shapeDirection == 'N')
			{

				body[1].x -= 1; body[1].y -= 1;
				body[2].x -= 2; body[2].y -= 2;
				body[3].x += 1; body[3].y -= 3;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[1].x += 1; body[1].y += 1;
				body[2].x += 2; body[2].y += 2;
				body[3].x -= 1; body[3].y += 3;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{
				body[1].x -= 1; body[1].y -= 1;
				body[2].x -= 2; body[2].y -= 2;
				body[3].x += 1; body[3].y -= 3;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[1].x += 1; body[1].y += 1;
				body[2].x += 2; body[2].y += 2;
				body[3].x -= 1; body[3].y += 3;
				this->shapeDirection = 'N';
				break;
			}
			break;
		case 4: //SQ
			//square is the same
			break;
		case 5: //ZL
			if (this->shapeDirection == 'N')
			{

				body[1].y += 1;
				body[3].x -= 2; body[3].y += 1;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[1].y -= 1;
				body[3].x += 2; body[3].y -= 1;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{

				body[1].y += 1;
				body[3].x -= 2; body[3].y += 1;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[1].y -= 1;
				body[3].x += 2; body[3].y -= 1;
				this->shapeDirection = 'N';
				break;
			}
			break;
		case 6: //ZR

			if (this->shapeDirection == 'N')
			{

				body[1].y += 1;
				body[3].x += 2; body[3].y += 1;
				this->shapeDirection = 'E';
				break;
			}
			if (this->shapeDirection == 'E')
			{
				body[1].y -= 1;
				body[3].x -= 2; body[3].y -= 1;
				this->shapeDirection = 'S';
				break;
			}
			if (this->shapeDirection == 'S')
			{

				body[1].y += 1;
				body[3].x += 2; body[3].y += 1;
				this->shapeDirection = 'W';
				break;
			}
			if (this->shapeDirection == 'W')
			{
				body[1].y -= 1;
				body[3].x -= 2; body[3].y -= 1;
				this->shapeDirection = 'N';
				break;
			}
			break;
		}



	}


}