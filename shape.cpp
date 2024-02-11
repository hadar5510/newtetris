#include "shape.h"
#include <cstdlib>
#include <windows.h>

//shape::shape(const shape& other)
//{
//
//	type = other.type;
//	shapeDirection = other.shapeDirection;
//
//	for (int i = 0; i < 4; i++)
//	{
//		body[i] = other.body[i];
//	}
//}



//intializing shape
void Shape::init(int minX, int minY, int shapetype)
{
	this->type = shapetype;
	this->shapeDirection = 'N';
	this->color = 0;
	switch (shapetype)
	{
	case L_LEFT:

		this->color = 16;									//blue
		body[0] = Point(minX + GAME_WIDTH / 2, minY);
		body[1] = Point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = Point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = Point(minX + GAME_WIDTH / 2 - 1, minY + 2);
		break;
	case L_RIGHT:

		this->color = 32;									//green
		body[0] = Point(minX + GAME_WIDTH / 2, minY);
		body[1] = Point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = Point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = Point(minX + GAME_WIDTH / 2 + 1, minY + 2);
		break;
	case T_SHAPE:

		this->color = 48;									//cyan
		body[0] = Point(minX + GAME_WIDTH / 2, minY);
		body[1] = Point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = Point(minX + GAME_WIDTH / 2 - 1, minY);
		body[3] = Point(minX + GAME_WIDTH / 2, minY + 1);	 //chupchik of T shape
		break;
	case LINE:

		this->color = 64;									//red
		body[0] = Point(minX + GAME_WIDTH / 2, minY);
		body[1] = Point(minX + GAME_WIDTH / 2, minY + 1);
		body[2] = Point(minX + GAME_WIDTH / 2, minY + 2);
		body[3] = Point(minX + GAME_WIDTH / 2, minY + 3);
		break;
	case SQUARE:

		this->color = 80;									//purple
		body[0] = Point(minX + GAME_WIDTH / 2, minY);
		body[1] = Point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = Point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = Point(minX + GAME_WIDTH / 2 + 1, minY + 1);
		break;
	case Z_LEFT:

		this->color = 96;									//orange
		body[0] = Point(minX + GAME_WIDTH / 2, minY);
		body[1] = Point(minX + GAME_WIDTH / 2 - 1, minY);
		body[2] = Point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = Point(minX + GAME_WIDTH / 2 + 1, minY + 1);
		break;
	case Z_RIGHT:

		this->color = 112;									//grey
		body[0] = Point(minX + GAME_WIDTH / 2, minY);
		body[1] = Point(minX + GAME_WIDTH / 2 + 1, minY);
		body[2] = Point(minX + GAME_WIDTH / 2, minY + 1);
		body[3] = Point(minX + GAME_WIDTH / 2 - 1, minY + 1);
		break;
	}


}


//int Shape::initColor(bool backroundColor)
//{
//	int randColor = rand() % 6;
//
//	if (!backroundColor)												//black color
//		return FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
//	
//	switch (randColor)
//	{
//	case 0:
//		return FOREGROUND_BLUE;
//	case 1:
//		return BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
//	case 2:
//		return FOREGROUND_GREEN;
//	case 3:
//		return FOREGROUND_RED;
//	case 4:
//		return 50;
//	case 5:
//		return 22;
//	}
//
//}

//updating board to the current position after moving
void Shape::move(char keyPressed)
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
	case P1_LEFT:
	case P2_LEFT:
		//LEFT
		for (int i = 0; i < 4; i++)
		{
			body[i].x = body[i].x - 1;
		}

		break;
	case P1_RIGHT:
	case P2_RIGHT:
		//RIGHT
		for (int i = 0; i < 4; i++)
			body[i].x = body[i].x + 1;

		break;
	case P1_DROP:
	case P2_DROP:
		//DROP
		for (int i = 0; i < 4; i++)
		{
			body[i].y = body[i].y + 1;
		}
		break;
	case P1_ROTATE_CLOCK:
	case P2_ROTATE_CLOCK:

		rotate(CLOCKWISE);

		break;
	case P1_ROTATE_ANTI_CLOCK:
	case P2_ROTATE_ANTI_CLOCK:

		rotate(ANTI_CLOCKWISE);

		break;
	}


}


//rotate shape according to direction - NORTH/WEST/EAST/SOUTH
void Shape::rotate(int direction)
{

	if (direction == CLOCKWISE)
	{
		rotateClock();
	}
	else
	{
		rotateAntiClock();
	}

}




void Shape::rotateAntiClock()
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




void Shape::rotateClock()
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