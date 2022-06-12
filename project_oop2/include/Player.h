#pragma once
#include "Object.h"
class Player :public Object{
public:
	Player(sf::Texture& t, sf::Vector2f f) : Object(t, f), m_x(0), m_y(0), m_dx(0), m_dy(0)
	{
		m_display.setOrigin(20, 40);  //to be changed
	}
	~Player() {}
	void moveP();
	int getPlayerXpos()const { return m_x; }
	int getPlayerYpos()const { return m_y; }
	void setPlayerDx(int x) {  m_dx= x; }
	void setPlayerDy(int y) {  m_dy=y; }
	void setPlayerPosition(sf::Vector2f v) { m_x = v.x; m_y = v.y; }
	void setRotation(int x) { m_display.setRotation(x); }
	bool isRight(int x)const;
	bool isUp(int y)const;
	bool isLeft(int y)const;
	bool isDown(int y)const;
private:
	int m_x,  m_y, m_dx,  m_dy;
};