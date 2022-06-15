#include "RandomMove.h"
#include "Board.h"

RandomMove::RandomMove(sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> placeToMove) :Move(pos, std::move(placeToMove))
{
	m_dx = BIG_JUMP_PIXELS;
	m_dy = BIG_JUMP_PIXELS;
	m_clockForMove.restart();
	m_direction = m_directions[rand() % DIRECTIONS_AMOUNT];
}
//פונקציה האחראית על תזוזה רנדומלית לא אלכסונית
//------------------------------------------------------------------------------
sf::Vector2f RandomMove::move(Board& b)
{
	int index = rand() % DIRECTIONS_AMOUNT;
	int delteTime = m_clockForMove.getElapsedTime().asMilliseconds();
	if (delteTime % FIFTY_SECONDS == ZERO)
		moveDifferently();
	m_y += m_direction.y * (m_dy);
	m_x += m_direction.x * (m_dx);
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
		(m_x <= 370) || (m_x >= 1230) || (m_y <= 70) || (m_y >= 930))
	{
		m_x -= m_direction.x * (m_dx);
		m_y -= m_direction.y * (m_dy);
		if ( m_direction == m_directions[index])
			m_direction = m_directions[(index + 1) % DIRECTIONS_AMOUNT];
		else
			m_direction = m_directions[index];
	}
	return sf::Vector2f(m_x, m_y);
}
//פונקציה האחראית על שינוי כיוון התזוזה הרנדומלית
//------------------------------------------------------------------------------
void RandomMove::moveDifferently()
{
	m_direction = -m_direction;
	if (m_direction == sf::Vector2i(0, 1) || m_direction == sf::Vector2i(0, -1))
	{
		if ( (m_x <= 800) && (m_x + 20) < 1230)
			m_x += 20;
		else if ((m_x > 800) && (m_x - 20) > 370)
			m_x -= 20;
	}
	else if (m_direction == sf::Vector2i(1, 0) || m_direction == sf::Vector2i(-1, 0))
	{
		if ( (m_y <= 500) && (m_y + 20) < 930)
			m_y += 20;
		else if ((m_y > 500) && (m_y - 20) > 70)
			m_y -= 20;
	}

}