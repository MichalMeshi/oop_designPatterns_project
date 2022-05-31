#include "Move.h"
Move::Move(std::unique_ptr<CanMoveToPlace> placeToMove) :m_placeToMove(std::move(placeToMove)) {}
sf::Vector2i Move::getIndex()const { return sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20); }