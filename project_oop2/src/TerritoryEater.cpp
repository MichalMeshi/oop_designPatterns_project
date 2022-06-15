#include "TerritoryEater.h"
#include "Board.h"
//פונקציה האחראית על תזוזת האוכל שטחים
void TerritoryEater::move(Board& b)
{
	sf::Vector2f pos;
	if (m_move != nullptr)
	{
		pos = m_move->move(b);
		m_display.setPosition(pos);
		b.eatCellInMatrix((pos.y-50)/20,(pos.x-350)/20);
	}
}

