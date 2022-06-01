#pragma once
#include "StaticObj.h"
class Gift: public StaticObj
{
public:
	 Gift(sf::Texture& t, sf::Vector2f f):StaticObj(t,f)
	 {
		 float x = (rand() % 1250) + 950;
		 float y = (rand() % 950) + 50;
		 m_display.setPosition(sf::Vector2f(x, y));
	 }
	 virtual ~Gift() = 0 {}
protected:

};