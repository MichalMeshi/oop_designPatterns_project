#pragma once
#include "StaticObj.h"
#include "Animation.h"
class Level;
class Gift: public StaticObj
{
public:
	Gift(sf::Texture& t, sf::Vector2f f, Level* level) ;
	 virtual ~Gift() = 0 {}
	 void handleAnimation()	{ m_animation.handleAnimation();}
	 void deleted() { m_isDeleted = true; }
	 bool isDead()const { return m_isDeleted; }
protected:
	Level* m_level;
	Animation m_animation;
	bool m_isDeleted = false;
};