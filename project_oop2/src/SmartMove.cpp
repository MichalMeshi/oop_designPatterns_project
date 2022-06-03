#include "SmartMove.h"
#include "Board.h"
sf::Vector2f SmartMove::move(Board& b)
{
	sf::Vector2f direction;
	direction = b.findDirectionToMove(m_x,m_y);
	m_y += direction.y * std::abs(m_dy);
	m_x += direction.x * std::abs(m_dx);

	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
		(m_x < 350) || (m_x > 1250)|| (m_y < 50) || (m_y > 950))
	{
		m_x -= direction.x * std::abs(m_dx);
		m_y -= direction.y * std::abs(m_dy);

	}
	/*m_y += direction.y * std::abs(m_dy);
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
		(m_y < 50) || (m_y > 950))
	{
		m_y -= direction.y * std::abs(m_dy);

	}*/





	return sf::Vector2f(m_x, m_y);
}

