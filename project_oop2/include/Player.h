#pragma once
#include "Object.h"
class Player :public Object{
public:
	Player(sf::Texture& t,sf::Vector2f f) :Object(t, f), m_x(0), m_y(0)
	,m_dx(0),m_dy(0) { m_display.setOrigin(); }
	~Player() {}
	void moveP()
	{
		m_x += m_dx;
		m_y += m_dy;
		if (m_x < 0) m_x = 0; if (m_x > 44) m_x = 44;
		if (m_y < 0) m_y = 0; if (m_y > 44) m_y = 44;
		setPosition(sf::Vector2f(350 + (m_x * 20), 50 + (m_y * 20)));
	}
	int getPlayerXpos()const { return m_x; }
	int getPlayerYpos()const { return m_y; }
	void setPlayerDx(int x) {  m_dx= x; }
	void setPlayerDy(int y) {  m_dy=y; }

	bool isRight(int x);
	bool isUp(int y);
	bool isLeft(int y);
	bool isDown(int y);
private:
	int m_x,  m_y, m_dx,  m_dy;
};