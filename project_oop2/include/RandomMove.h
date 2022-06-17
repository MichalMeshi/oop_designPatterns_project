#pragma once
#include "Move.h"
#include "EnemyFactory.h"
//-----------------------------------------------
class RandomMove :public Move{
public:
	RandomMove(sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> placeToMove);
	~RandomMove() = default;
	virtual sf::Vector2f move(Board& b) override; 
	void moveDifferently();
private:
	static bool m_register;
	int m_directionEnum = rand() % DIRECTIONS_AMOUNT;
	sf::Vector2i m_direction = {ZERO,ZERO};
	sf::Clock m_clockForMove;
	std::vector<sf::Vector2i> m_directions = {UP, DOWN, RIGHT, LEFT };
};
bool RandomMove::m_register = EnemyFactory::registerMove(RANDOM_MOVE, [](sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> p)->std::shared_ptr<Move> { return std::make_shared<RandomMove>(pos, std::move(p)); });
