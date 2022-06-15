#include "SmartMove.h"
#include "Board.h"

SmartMove::SmartMove(sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> placeToMove)
	:Move(pos, std::move(placeToMove)) { m_dx = SIX; m_dy = SIX; }
//פונקציה המבצעת את התזוזה החכמה הישרה הרודפת אחרי השחקן 
sf::Vector2f SmartMove::move(Board& b)
{
	sf::Vector2f direction;
	direction = b.findDirectionToMove(m_x,m_y);
	m_y += direction.y * std::abs(m_dy);
	m_x += direction.x * std::abs(m_dx);

	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
		(m_x < 370) || (m_x > 1230)|| (m_y < 70) || (m_y > 930))
	{
		m_x -= direction.x * std::abs(m_dx);
		m_y -= direction.y * std::abs(m_dy);

	}
	return sf::Vector2f(m_x, m_y);
}

