#pragma once
#include "Move.h"
class MoveFar:public Move
{
public:
	MoveFar() {}
	~MoveFar() {}
	virtual sf::Vector2f move(Board& b) override{}
private:
};