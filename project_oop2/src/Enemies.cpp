#include "Enemies.h"
#include "Level.h"

void Enemies::move(Board& b)
{ 
	m_display.setPosition(m_move->move(b)); 
	m_display.rotate();
	//m_display.setOrigin({ 0,0 });

}
void Enemies::reduceLife() { m_level->reduceLife(); }

