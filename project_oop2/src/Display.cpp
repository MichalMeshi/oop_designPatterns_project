#include "Display.h"

Display::Display(const sf::Texture& t, sf::Vector2f scale) :m_sprite(sf::Sprite(t))
{
	m_sprite.setScale(scale.x / m_sprite.getGlobalBounds().width, scale.y / m_sprite.getGlobalBounds().height);
}
//------------------------------------------------------------
Display::Display(const sf::Texture& t, sf::Vector2f position, sf::Vector2f scale):Display(t,scale)
{
	m_sprite.setPosition(position);
}
