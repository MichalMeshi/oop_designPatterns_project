#include "RandomMove.h"
#include "Board.h"
//------------------------------------------------------------
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
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - BEGGINING_OF_BOARD_Y) / BOARD_GAME_CELL_SIZE, (m_x - BEGGINING_OF_BOARD_X) / BOARD_GAME_CELL_SIZE), b) ||
		(m_x <= LEFT_LIMIT) || (m_x >= RIGHT_LIMIT) || (m_y <= TOP_LIMIT) || (m_y >= BOTTOM_LIMIT))
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
	if (m_direction == DOWN || m_direction == UP)
	{
		if ( (m_x <= MIDDLE_BOARD_X) && (m_x + BOARD_GAME_CELL_SIZE) < RIGHT_LIMIT)
			m_x += BOARD_GAME_CELL_SIZE;
		else if ((m_x > MIDDLE_BOARD_X) && (m_x - BOARD_GAME_CELL_SIZE) > LEFT_LIMIT)
			m_x -= BOARD_GAME_CELL_SIZE;
	}
	else if (m_direction ==RIGHT || m_direction == LEFT)
	{
		if ( (m_y <= MIDDLE_BOARD_Y) && (m_y + BOARD_GAME_CELL_SIZE) < BOTTOM_LIMIT)
			m_y += BOARD_GAME_CELL_SIZE;
		else if ((m_y > MIDDLE_BOARD_Y) && (m_y - BOARD_GAME_CELL_SIZE) > TOP_LIMIT)
			m_y -= BOARD_GAME_CELL_SIZE;
	}
}
