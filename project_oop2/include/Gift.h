#pragma once
#include "StaticObj.h"
class Level;
class Gift: public StaticObj
{
public:
	Gift(sf::Texture& t, sf::Vector2f f, Level* level) ;
	 virtual ~Gift() = 0 {}
	 void rotate() { m_display.rotate(); }

protected:
	Level* m_level;
};