#pragma once
#include "DynamicObj.h"
#include "Move.h"
#include "CanMoveToPlace.h"
class Enemies:public DynamicObj
{
public:
	Enemies() = default;
	Enemies(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2, std::unique_ptr<Move> m,  std::unique_ptr<CanMoveToPlace> c)
		:DynamicObj(t,f1,f2), m_move(std::move(m)), m_placeToMove(std::move(c)) {}
	~Enemies() {}
	virtual void move(Board& b)override { m_display.setOrigin(sf::Vector2f(15, 15)); m_display.setPosition(m_move->move(b)); m_display.rotate();}
	sf::Vector2i getIndex()const { return m_move->getIndex(); }
protected:
	
	std::unique_ptr<Move> m_move;
	std::unique_ptr<CanMoveToPlace> m_placeToMove;
};

