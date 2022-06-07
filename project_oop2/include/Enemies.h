#pragma once
#include "DynamicObj.h"
#include "Move.h"
class Level;
class Enemies:public DynamicObj   {
public:
	Enemies() = default;
	Enemies(sf::Texture& t, sf::Vector2f f, std::shared_ptr<Move> m,Level* l)
		:DynamicObj(t, f), m_move(m), m_prevMove(m_move), m_level(l) {
		m_display.setOrigin();}
	~Enemies() {}
	virtual void move(Board& b)override;
	sf::Vector2i getIndex()const {
		return m_prevMove->getIndex();
	}
	void reduceLife();
	void freeze() { m_move = NULL; }
	void unFreeze() { m_move = m_prevMove; }
protected:	
	std::shared_ptr<Move> m_move;
	std::shared_ptr<Move> m_prevMove;
	Level* m_level;
};

