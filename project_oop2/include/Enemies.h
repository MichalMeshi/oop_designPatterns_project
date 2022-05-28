#pragma once
#include "DynamicObj.h"
#include "SimpleMove.h"
class Enemies:public DynamicObj
{
public:
	Enemies() = default;
	Enemies(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):DynamicObj(t,f1,f2), m_move(std::move(std::make_unique<SimpleMove>())) {}
	~Enemies() {}
	virtual bool move(Board& b) = 0{}
	sf::Vector2i getIndex()const { return m_move->getIndex(); }
protected:
	
	std::unique_ptr<Move> m_move;
};

