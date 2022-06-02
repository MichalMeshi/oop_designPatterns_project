#pragma once
#include "CanMoveToPlace.h"
class Move{
public:
	Move(sf::Vector2i pos,std::unique_ptr<CanMoveToPlace> placeToMove); 
	virtual ~Move()=0{}
	virtual sf::Vector2f move(Board& b) = 0{}
	sf::Vector2i getIndex()const; 

protected:
	int m_x = 800, m_y = 500;
	int m_dx =   5 - rand() % 10;
	int m_dy =  5 - rand() % 10;
	std::unique_ptr<CanMoveToPlace> m_placeToMove;
};