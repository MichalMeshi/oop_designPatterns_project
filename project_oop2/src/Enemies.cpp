#include "Enemies.h"
#include "Level.h"
Enemies::Enemies(sf::Texture& t, std::shared_ptr<Move> m, Level* l)
	:DynamicObj(t, sf::Vector2f(30, 30)), m_move(m), m_prevMove(m_move), m_level(l)
{
	m_display.setOrigin();
}
void Enemies::move(Board& b)
{ 
	if (m_move != nullptr)
	{
		m_display.setPosition(m_move->move(b));
		m_display.rotate();
	}
}
void Enemies::reduceLife() { m_level->reduceLife(); }

