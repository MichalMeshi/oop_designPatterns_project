#include "SmartMove.h"
#include "Board.h"
sf::Vector2f SmartMove::move(Board& b)
{
	m_x += m_dx;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20),b))
	{
		m_dx = -m_dx;
		m_x += m_dx;
	}
	m_y += m_dy;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b))
	{
		m_dy = -m_dy;
		m_y += m_dy;
	}
	//if (((m_x - 350) / 20 < 0)) m_x = 350; if (((m_x - 350) / 20) > 44) m_x = 1230;//μϊχο
	//if (((m_y - 50) / 20 < 0)) m_y = 50; if (((m_y - 50) / 20 > 44)) m_y = 930;
	return sf::Vector2f(m_x, m_y);
}

