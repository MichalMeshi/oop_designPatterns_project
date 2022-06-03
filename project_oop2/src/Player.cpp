#include "Player.h"
void Player::moveP()
{
	m_x += m_dx;
	m_y += m_dy;
	if (m_x < 0) m_x = 0; if (m_x > 44) m_x = 44;
	if (m_y < 0) m_y = 0; if (m_y > 44) m_y = 44;
	setPosition(sf::Vector2f(350 + (m_x * 20), 50 + (m_y * 20)));
}
bool Player::isRight(int x_pos)
{
	return (m_x > ((x_pos - 350) / 20));
}
bool Player::isLeft(int x_pos)
{
	return (m_x < ((x_pos - 350) / 20));
}
bool Player::isUp(int y_pos)
{
	return (m_y < ((m_y - 50) / 20));
}
bool Player::isDown(int y_pos)
{
	return (m_y > ((m_y - 50) / 20));
}
