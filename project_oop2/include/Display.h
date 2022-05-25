#pragma once
#include "Graphics.h"
class Display{
public:
	Display(const sf::Texture& t, sf::Vector2f position, sf::Vector2f scale);
	sf::Sprite getSprite() { return m_sprite; }
	void draw(sf::RenderWindow& window) { window.draw(m_sprite); }
	void setPosition(int x, int y) { m_sprite.setPosition(sf::Vector2f(x,y)); }
	void setOrigin(sf::Vector2f f) { m_sprite.setOrigin(f); }
private:
	sf::Sprite m_sprite;

};