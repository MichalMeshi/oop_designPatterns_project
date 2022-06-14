#pragma once
#include "StaticObj.h"
#include "Animation.h"
class Level;
class Gift: public StaticObj
{
public:
	Gift(sf::Texture& t, sf::Vector2f f, Level* level) ;
	 virtual ~Gift() = 0 {}
	// virtual void rotate() { m_display.rotate(); }
	 void handleAnimation()
	 {
		 m_animation.handleAnimation();
	 }
protected:
	Level* m_level;
	Animation m_animation;
};