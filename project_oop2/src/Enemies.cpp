#include "Enemies.h"
#include "Level.h"

void Enemies::move(Board& b)
{ 
	if (m_move != nullptr)
	{
		m_display.setPosition(m_move->move(b));
		m_display.rotate();
	}

}
void Enemies::reduceLife() { m_level->reduceLife(); }

