#include "TerritoryEater.h"
#include "Board.h"
void TerritoryEater::move(Board& b)
{
	sf::Vector2f pos;
	if (m_move != nullptr)
	{
		pos = m_move->move(b);
		m_display.setPosition(pos);
		//m_display.rotate();
		b.eatCellInMatrix((pos.y-50)/20,(pos.x-350)/20,m_level);
	}
}
//להחליף לו כיוון כל כמה שניות
//לבדוק שהבעיה לא נשארה...
