#include "Player.h"//void Player::moveP(int& x, int& y, int& dx, int& dy)//{//	x += dx;//	y += dy;//	if (x < 0) x = 0; if (x > 44) x = 44;//	if (y < 0) y = 0; if (y > 44) y = 44;//	setPosition(sf::Vector2f(350 + (y * 20), 50 + (x * 20)));//}
bool Player::isRight(int x_pos)
{
	return (m_x > ((x_pos - 350) / 20));
}
bool Player::isLeft(int x_pos)
{
	return (m_x > ((x_pos - 350) / 20));
}
bool Player::isUp(int y_pos)
{
	return (m_y < ((m_y - 50) / 20));
}
bool Player::isDown(int y_pos)
{
	return (m_y > ((m_y - 50) / 20));
}
