#pragma once
#include "DynamicObj.h"
#include "Move.h"
class Level;
class Enemies:public DynamicObj   {
public:
	Enemies() = default;
	Enemies(sf::Texture& t, sf::Vector2f f, std::unique_ptr<Move> m,Level* l)
		:DynamicObj(t, f), m_move(std::move(m)), m_level(l) {
		m_display.setOrigin();}
	~Enemies() {}
	virtual void move(Board& b)override;
	sf::Vector2i getIndex()const { return m_move->getIndex(); }
	void reduceLife();
protected:	
	std::unique_ptr<Move> m_move;
	std::unique_ptr<Move> m_prevMove=NULL;
	Level* m_level;
};

