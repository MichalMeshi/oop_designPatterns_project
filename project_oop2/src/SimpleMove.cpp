#include "SimpleMove.h"
sf::Vector2f SimpleMove::move(Board& b)
{
	m_x += m_dx;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b))
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
	return sf::Vector2f(m_x, m_y);
}