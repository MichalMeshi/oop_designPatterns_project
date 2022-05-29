#pragma once
#include "Move.h"
#include "EnemyFactory.h"
class MoveFar:public Move
{
public:
	MoveFar() {}
	~MoveFar() {}
	virtual sf::Vector2f move(Board& b) override{ return sf::Vector2f(x, y); }
private:
	static bool m_register;
};
bool MoveFar::m_register = EnemyFactory::registerMove(MOVE_FAR,[]()->std::unique_ptr<Move> { return std::make_unique<MoveFar>(); });
