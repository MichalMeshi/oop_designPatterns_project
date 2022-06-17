#pragma once
#include "Move.h"
#include "EnemyFactory.h"
//-----------------------------------------------
class SimpleMove :public Move{
public:
	SimpleMove(sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> placeToMove) :Move(pos,std::move(placeToMove)) {}
	~SimpleMove() {}
	virtual sf::Vector2f move(Board& b) override;
private:
	static bool m_register;
};
bool SimpleMove::m_register = EnemyFactory::registerMove(SIMPLE_MOVE, [](sf::Vector2i pos,std::unique_ptr<CanMoveToPlace> placeToMove)->std::shared_ptr<Move> { return std::make_shared<SimpleMove>(pos,std::move(placeToMove)); });
