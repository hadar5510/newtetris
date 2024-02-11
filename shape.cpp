#include "shape.h"


//intializing shape
void shape::init(int minX, int minY, int shapetype)
{
	this->type = shapetype;
	this->shapeDirection = 'N';

	switch (shapetype)
	{
	case L_LEFT: 



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = point(minX + GAME_WIDTH / 2 - 1, minY + 2);
		break;
	case L_RIGHT: 



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = point(minX + GAME_WIDTH / 2 + 1, minY + 2);
		break;
	case T_SHAPE: 



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = point(minX + GAME_WIDTH / 2 - 1, minY);
		body[3] = point(minX + GAME_WIDTH / 2, minY + 1);	 //chupchik of T shape
		break;
	case LINE: 

		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = point(minX + GAME_WIDTH / 2, minY + 3);
		break;
	case SQUARE: 

		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = point(minX + GAME_WIDTH / 2 + 1, minY + 1);
		break;
	case Z_LEFT: 



		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2 - 1, minY);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = point(minX + GAME_WIDTH / 2 + 1, minY + 1);
		break;
	case Z_RIGHT: 


		body[0] = point(minX + GAME_WIDTH / 2, minY);
		body[1] = point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = point(minX + GAME_WIDTH / 2 - 1, minY + 1);
		break;
	}


}


//updating board to the current position after moving
void shape::move(char keyPressed)
{


	if (keyPressed == DOWN)
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
			body[i].x = body[i].x + 1;
		
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
		
		rotate(CLOCKWISE);

		break;
	case 'W':
	case 'I':
		
		rotate(ANTI_CLOCKWISE);

		break;
	}


}


//rotate shape according to direction - NORTH/WEST/EAST/SOUTH
void shape::rotate(int direction)
{

	if (direction == CLOCKWISE)
	{

		switch (this->type)
		{
		case L_LEFT: //LL

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
		case L_RIGHT: //LR

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
		case T_SHAPE: //T


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
		case LINE: //I

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
		case SQUARE: //SQ
			//square is the same
			break;
		case Z_LEFT: //ZL
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
		case Z_RIGHT: //ZR

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




	if (direction == ANTI_CLOCKWISE)
	{

		switch (this->type)
		{
		case L_LEFT: 

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
		case L_RIGHT: 

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
		case T_SHAPE: 


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
		case LINE: 

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
		case SQUARE: 
			//square is the same
			break;
		case Z_LEFT: 
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
		case Z_RIGHT: 

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