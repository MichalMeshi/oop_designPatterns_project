#pragma once
#include "Move.h"
#include "EnemyFactory.h"

class SmartMove :public Move
{
public:
	SmartMove(sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> placeToMove) :Move(pos, std::move(placeToMove)) { m_dx = 6; m_dy = 6; }
	~SmartMove() {}
	virtual sf::Vector2f move(Board& b) override;
private:
	static bool m_register;
};
bool SmartMove::m_register = EnemyFactory::registerMove(SMART_MOVE, [](sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> p)->std::shared_ptr<Move> { return std::make_shared<SmartMove>(pos,std::move(p)); });
