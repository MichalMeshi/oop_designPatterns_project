#include "SimpleMove.h"
sf::Vector2f SimpleMove::move(Board& b)
{
	m_x += m_dx;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) || 
		(m_x<370) ||  (m_x>1230))
	{
		m_dx = -m_dx;
		m_x += m_dx;
	}
	m_y += m_dy;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b)||
		 (m_y<70) || (m_y>930))
	{
		m_dy = -m_dy;
		m_y += m_dy;
	}
	//if (((m_x - 350) / 20 < 0)) m_x += 20; if (((m_x - 350) / 20) > 44) m_x -= 20;//μϊχο
	//if (((m_y - 50) / 20 < 0)) m_y+=20; if (((m_y - 50) / 20 > 44)) m_y -=20;
	//if(b.checkIfContainedInRec(m_x))
	return sf::Vector2f(m_x, m_y);
}