#pragma once
#include "StaticObj.h"
class Gift: public StaticObj
{
public:
	 Gift(sf::Texture& t, sf::Vector2f f):StaticObj(t,f)
	 {
		 float x = (rand() % 890) + 350;
		 float y = (rand() % 890) + 50;
		 m_display.setPosition(sf::Vector2f(x, y));
	 }
	 virtual ~Gift() = 0 {}
protected:

};