#include "Move.h"
//------------------------------------------------------------
Move::Move(sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> placeToMove) :m_placeToMove(std::move(placeToMove)),m_x(pos.x),m_y(pos.y) {}
//------------------------------------------------------------
sf::Vector2i Move::getIndex()const
{ 
	return sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20);
}