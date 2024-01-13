#include "shapes.h"
#include "gameConfig.h"
#include "point.h"
#include "general.h"
#include <stdbool.h>

#define LEFTMOVE 1
#define RIGHTMOVE 2
#define DOWNMOVE 0

void shapes::init(const Point& head, char ch, int color)
{
	this->ch = ch;
	this->backgroundcolor = color;
	body[0] = head;
	body[0].draw(ch, backgroundcolor);
	for (int i = 1; i < 4; i++)
	{
		body[i] = body[i - 1];
		body[i].move((GameConfig::eKeys)0);
		body[i].draw(ch, backgroundcolor);
	}
}


void shapes::move(GameConfig::eKeys direction)
{
	bool valid = true;

	//switch (direction)
	//{
	//case GameConfig::eKeys::LEFT:
	//	valid = legalmove(LEFTMOVE);
	//	break;
	//case GameConfig::eKeys::RIGHT:
	//	valid = true;
	//	break;
	//case GameConfig::eKeys::DOWN:
	//	valid = true;
	//	break;
	//}

	if (valid)
	{
		for (int i = 3; i >= 0; i--)
		{
			body[i].draw(' ', GameConfig::COLORS[0]);

		}
		for (int i = 3; i >= 0; i--)
		{

			body[i].move(direction);
			body[i].draw(ch, backgroundcolor);
		}

	}

	
}


//bool shapes::legalmove(int move)
//{
//
//	int minX, maxX, maxY;
//	char check;
//	bool invalid;
//	int counter = 0;
//
//	if (move == LEFTMOVE)
//	{
//		for (int i = 3; i >= 0; i--)
//		{
//			counter = 0;
//			check = getCharAtPosition(body[i].x - 1, body[i].y);
//
//			if (check != ' ')
//			{
//				for (int k = 0; k >= 0; k--)
//				{
//					if (body[k].x == body[i].x - 1 && body[k].y == body[i].y)
//						counter++;
//
//				}
//				if (counter == 0)
//				return false;
//
//			}
//		}
//
//	}
//
//
//	return true;
//
//}