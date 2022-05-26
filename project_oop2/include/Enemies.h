#pragma once
#include "DynamicObj.h"
#include "SimpleMove.h"
class Enemies:public DynamicObj
{
public:
	Enemies(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):DynamicObj(t,f1,f2), m_move(std::make_unique<SimpleMove>()) {}
	~Enemies() {}
	virtual bool move(Board& b) override { return false; }
	sf::Vector2i getIndex()const { return sf::Vector2i((y - 50) / 20, (x - 350) / 20); }
protected:
	int x = 500, y = 500;
	int dx = 4 - rand() % 8;
	int dy = 4 - rand() % 8;
	std::unique_ptr<Move> m_move;
};

