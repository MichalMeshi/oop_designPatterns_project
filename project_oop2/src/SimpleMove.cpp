#include "SimpleMove.h"
//-------------------------------------------------------
//פונקציה המבצעת תזוזה רגילה
//-------------------------------------------------------
sf::Vector2f SimpleMove::move(Board& b)
{
	m_x += m_dx;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - BEGGINING_OF_BOARD_Y) / BOARD_GAME_CELL_SIZE, (m_x - BEGGINING_OF_BOARD_X) / BOARD_GAME_CELL_SIZE), b) ||
		(m_x< LEFT_LIMIT+ (GIFT_PIC_SIZE / 2)) ||  (m_x> RIGHT_LIMIT- (GIFT_PIC_SIZE / 2)))
	{
		m_dx = -m_dx;
		m_x += m_dx;
	}
	m_y += m_dy;
	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - BEGGINING_OF_BOARD_Y) / BOARD_GAME_CELL_SIZE, (m_x - BEGGINING_OF_BOARD_X) / BOARD_GAME_CELL_SIZE), b)||
		 (m_y< TOP_LIMIT+ (GIFT_PIC_SIZE / 2)) || (m_y> BOARD_GAME_LENGTH+(GIFT_PIC_SIZE/2)))
	{
		m_dy = -m_dy;
		m_y += m_dy;
	}
	return sf::Vector2f(m_x, m_y);
}
