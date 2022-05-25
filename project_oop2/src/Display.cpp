#include "Display.h"
Display::Display(const sf::Texture& t, sf::Vector2f position, sf::Vector2f scale)
{
	auto s = sf::Sprite(t);
	m_sprite = s;
	m_sprite.setPosition(position);
	m_sprite.setScale(scale.x / s.getGlobalBounds().width, scale.y / s.getGlobalBounds().height);
}