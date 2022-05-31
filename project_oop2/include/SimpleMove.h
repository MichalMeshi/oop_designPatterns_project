#pragma once
#include "Move.h"
#include "EnemyFactory.h"

class SimpleMove :public Move
{
public:
	SimpleMove(std::unique_ptr<CanMoveToPlace> placeToMove) :Move(std::move(placeToMove)) {}
	~SimpleMove() {}
	virtual sf::Vector2f move(Board& b) override;
private:
	static bool m_register;
};
bool SimpleMove::m_register = EnemyFactory::registerMove(SIMPLE_MOVE, [](std::unique_ptr<CanMoveToPlace> placeToMove)->std::unique_ptr<Move> { return std::make_unique<SimpleMove>(std::move(placeToMove)); });
