#include "RandomMove.h"
#include "Board.h"

RandomMove::RandomMove(sf::Vector2i pos, std::unique_ptr<CanMoveToPlace> placeToMove) :Move(pos, std::move(placeToMove))
{
	m_dx = 0;
}
//	//להפוך לסוויצ
//	if (m_directionEnum == UP)
//		m_direction = { 0,-1 };
//	if (m_directionEnum == DOWN)
//		m_direction = { 0,1 };
//	if (m_directionEnum == RIGHT)
//		m_direction = { 1,0 };
//	if (m_directionEnum == LEFT)
//		m_direction = { -1,0 };
//}
//
//sf::Vector2f RandomMove::move(Board& b)
//{
//	m_y += m_direction.y * std::abs(m_dy);
//	m_x += m_direction.x * std::abs(m_dx);
//	switch (m_directionEnum)
//	{
//	case UP:
//	{
//
//		if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
//			(m_x < 370) || (m_x > 1230) || (m_y < 70) || (m_y > 930)) {
//			m_directionEnum = RIGHT;//שינוי כיוון הגמד
//			m_x -= m_direction.x * std::abs(m_dx);
//			m_y -= m_direction.y * std::abs(m_dy);
//			m_direction = { 1,0 };
//
//		}
//		break;
//	}
//	case RIGHT:
//	{
//		if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
//			(m_x < 370) || (m_x > 1230) || (m_y < 70) || (m_y > 930)) {
//			m_directionEnum = DOWN;
//			m_x -= m_direction.x * std::abs(m_dx);
//			m_y -= m_direction.y * std::abs(m_dy);
//			m_direction = { 0,1 };
//
//		}
//		break;
//	}
//	case DOWN:
//	{
//		if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
//			(m_x < 370) || (m_x > 1230) || (m_y < 70) || (m_y > 930)) {
//			m_directionEnum = LEFT;
//			m_x -= m_direction.x * std::abs(m_dx);
//			m_y -= m_direction.y * std::abs(m_dy);
//			m_direction = { -1,0 };
//
//		}
//		break;
//	}
//	case LEFT:
//	{
//		if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
//			(m_x < 370) || (m_x > 1230) || (m_y < 70) || (m_y > 930)) {
//			m_directionEnum = UP;
//			m_x -= m_direction.x * std::abs(m_dx);
//			m_y -= m_direction.y * std::abs(m_dy);
//			m_direction = { 0,-1 };
//
//		}
//
//		break;
//	}
//	default:
//		break;
//	}
//	//לעשות תזוזה כמו של הגמדים
//	return sf::Vector2f(m_x, m_y);
//}

sf::Vector2f RandomMove::move(Board& b)
{
	int i = rand() % 2;
	if (i == 0)
		m_x=(m_x+1)%45;
	else
	  m_y=(m_y + 1) % 45

	if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b)
		|| (m_x < 370) || (m_x > 1230) || (m_y < 70) || (m_y > 930)) 
	{
		if ((m_x < 370) || (m_x > 1230))
		{
			m_cx = -m_cx;
			m_dx = m_cx;
			m_x += m_dx;
			m_y=0;
		}
		if ((m_y < 70) || (m_y > 930))
		{
			m_dx=0;
			m_cy = -m_cy;
			m_dy = m_cy;
			m_y += m_dy;
		}
		
	}
	
	//m_y += m_dy;
	//if (!m_placeToMove->ableToMoveToPlace(sf::Vector2i((m_y - 50) / 20, (m_x - 350) / 20), b) ||
	//	(m_y < 70) || (m_y > 930))
	//{
	//	m_dy = -m_dy;
	//	m_y += m_dy;
	//}

	return sf::Vector2f(m_x, m_y);
}

