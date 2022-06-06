#pragma once
#include "Move.h"
#include "EnemyFactory.h"

class RandomMove :public Move
{
public:
	RandomMove(sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> placeToMove) :Move(pos, std::move(placeToMove)) {}
	~RandomMove() {}
	virtual sf::Vector2f move(Board& b) override; 
private:
	static bool m_register;
};
bool RandomMove::m_register = EnemyFactory::registerMove(RANDOM_MOVE, [](sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> p)->std::unique_ptr<Move> { return std::make_unique<RandomMove>(pos, std::move(p)); });
