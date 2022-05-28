#pragma once
#include "Move.h"
class Board;
class SimpleMove :public Move
{
public:
	SimpleMove() :Move() {}
	~SimpleMove() {}
	virtual sf::Vector2f move(Board& b) override;
private:
};