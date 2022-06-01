#pragma once
#include "DynamicObj.h"
#include "Move.h"
class Enemies:public DynamicObj{
public:
	Enemies() = default;
	Enemies(sf::Texture& t, sf::Vector2f f, std::unique_ptr<Move> m)
		:DynamicObj(t, f), m_move(std::move(m)) {}
	~Enemies() {}
	virtual void move(Board& b)override;
	sf::Vector2i getIndex()const { return m_move->getIndex(); }
protected:	
	std::unique_ptr<Move> m_move;
};

