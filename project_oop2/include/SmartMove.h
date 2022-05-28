#pragma once
#include "Move.h"
class SmartMove :public Move
{
public:
	SmartMove() {}
	~SmartMove() {}
	virtual sf::Vector2f move(Board& b) override {}
};