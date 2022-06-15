#include "SimpleMove.h"

//פונקציה המבצעת תזוזה רגילה
sf::Vector2f SimpleMove::move(Board& b)
{
	m_x += m_dx;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) || 
		(m_x<385) ||  (m_x>1215))
	{
		m_dx = -m_dx;
		m_x += m_dx;
	}
	m_y += m_dy;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b)||
		 (m_y<85) || (m_y>915))
	{
		m_dy = -m_dy;
		m_y += m_dy;
	}
	return sf::Vector2f(m_x, m_y);
}
