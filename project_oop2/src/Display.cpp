#include "Display.h"
Display::Display(const sf::Texture& t, sf::Vector2f position, sf::Vector2f scale):m_sprite(sf::Sprite(t))
{
	m_sprite.setPosition(position);
	m_sprite.setScale(scale.x / m_sprite.getGlobalBounds().width, scale.y / m_sprite.getGlobalBounds().height);
	//m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}