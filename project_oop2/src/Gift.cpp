#include "Gift.h"
Gift::Gift(sf::Texture& t, sf::Vector2f f, Level* level) :StaticObj(t, f), m_level(level), m_animation(m_display,270,30)
{
	float x = (rand() % 890) + 350;
	float y = (rand() % 890) + 50;
	m_display.update(0, 30);
	m_display.setPosition(sf::Vector2f(x, y));
	m_display.setOrigin();
}