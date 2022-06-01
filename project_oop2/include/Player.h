#pragma once
#include "Object.h"
class Player :public Object{
public:
	Player(sf::Texture& t,sf::Vector2f f) :Object(t, f) { m_display.setOrigin(sf::Vector2f(15, 15)); }
	~Player() {}
	void moveP(int& x, int& y, int& dx, int&dy)
	{
		x += dx;
		y += dy;
		if (x < 0) x = 0; if (x > 44) x = 44;
		if (y < 0) y = 0; if (y > 44) y = 44;
		setPosition(sf::Vector2f(350 + (x * 20), 50 + (y * 20)));

	}

private:

};