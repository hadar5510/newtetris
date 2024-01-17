#pragma once
#include <stdbool.h>
#include "point.h"

class Shape
{

public:
	Point body[4];
	enum class ShapeType { LL, LR, T, I, SQ, ZL, ZR};
	char ch;
	int backgroundcolor;
	int type; //1 is line 2 is cube

	Shape(char ch, int color, Shape::ShapeType shapeType, int offset) {
		this->init(ch, color);

		body[0] = Point(offset + (GameConfig::GAME_WIDTH / 2), 1);
		body[1] = Point(offset + (GameConfig::GAME_WIDTH / 2), 2);
		body[2] = Point(offset + (GameConfig::GAME_WIDTH / 2), 3);
		body[3] = Point(offset + (GameConfig::GAME_WIDTH / 2) + 1, 3);
		//switch (shapeType)
		//{
		//default:
		//	//LL as only option for now
		//	body[0] = Point((GameConfig::GAME_WIDTH / 2), 5);
		//	body[1] = Point((GameConfig::GAME_WIDTH / 2), 10);
		//	body[2] = Point((GameConfig::GAME_WIDTH / 2), 8);
		//	body[3] = Point((GameConfig::GAME_WIDTH / 2) + 1, 4);
		//	break;
		//case Shape::ShapeType::LL:
		//	break;
		//case Shape::ShapeType::LR:
		//	break;
		//case Shape::ShapeType::T:
		//	break;
		//case Shape::ShapeType::I:
		//	break;
		//case Shape::ShapeType::SQ:
		//	break;
		//case Shape::ShapeType::ZL:
		//	break;
		//case Shape::ShapeType::ZR:
		//	break;
		//}
	}
	Shape() {}
	void init(char ch, int color);
	void move(GameConfig::eKeys direction);
	bool legalmove(int direction);
};