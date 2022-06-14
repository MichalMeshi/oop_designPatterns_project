#pragma once
#include "StaticObj.h"
class Level;
class Gift: public StaticObj
{
public:
	Gift(sf::Texture& t, sf::Vector2f f, Level* level) ;
	 virtual ~Gift() = 0 {}
	// virtual void rotate() { m_display.rotate(); }
	 void handleAnimation(){
		 m_display.update(pos.x, 30);
		 pos.x += 30;
		 if (pos.x == 270)
			 pos.x = 0;
	 }
protected:
	Level* m_level;
	sf::Vector2i pos = { 0,0 };
};