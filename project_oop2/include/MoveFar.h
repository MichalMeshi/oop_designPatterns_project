#pragma once
#include "Move.h"
#include "EnemyFactory.h"
class MoveFar:public Move
{
public:
	MoveFar(std::unique_ptr<CanMoveToPlace> placeToMove) :Move(std::move(placeToMove)) {}
	~MoveFar() {}
	virtual sf::Vector2f move(Board& b) override{ return sf::Vector2f(m_x, m_y); }
private:
	static bool m_register;
};
bool MoveFar::m_register = EnemyFactory::registerMove(MOVE_FAR,[](std::unique_ptr<CanMoveToPlace> placeToMove)->std::unique_ptr<Move> { return std::make_unique<MoveFar>(std::move(placeToMove)); });
