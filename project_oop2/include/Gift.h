#pragma once
#include "StaticObj.h"
class Level;
//#include "Level.h"
class Gift: public StaticObj
{
public:
	 Gift(sf::Texture& t, sf::Vector2f f,Level* level):StaticObj(t,f), m_level(level)
	 {
		 float x = (rand() % 890) + 350;
		 float y = (rand() % 890) + 50;
		 m_display.setPosition(sf::Vector2f(x, y));
		 m_display.setOrigin();
	 }
	 virtual ~Gift() = 0 {}
	 void rotate() { m_display.rotate(); }

protected:
	Level* m_level;
};