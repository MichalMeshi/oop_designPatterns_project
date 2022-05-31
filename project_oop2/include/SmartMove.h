#pragma once
#include "Move.h"
#include "EnemyFactory.h"

class SmartMove :public Move
{
public:
	SmartMove(std::unique_ptr<CanMoveToPlace> placeToMove) :Move(std::move(placeToMove)) {}
	~SmartMove() {}
	virtual sf::Vector2f move(Board& b) override;
private:
	static bool m_register;
};
bool SmartMove::m_register = EnemyFactory::registerMove(SMART_MOVE, [](std::unique_ptr<CanMoveToPlace> p)->std::unique_ptr<Move> { return std::make_unique<SmartMove>(std::move(p)); });
