#pragma once
#include "Graphics.h"
class Display{
public:
	Display(const sf::Texture& t, sf::Vector2f position, sf::Vector2f scale);
	Display(const sf::Texture& t,sf::Vector2f scale);

	sf::Sprite getSprite() { return m_sprite; }
	void draw(sf::RenderWindow& window) { window.draw(m_sprite); }
	void setPosition(sf::Vector2f v) { m_sprite.setPosition(v); }
	void setOrigin(sf::Vector2f f) { m_sprite.setOrigin(f.x,f.y); }
	void setColor(sf::Color c) { m_sprite.setColor(c); }
	void rotate() {  m_sprite.rotate(10); }
private:
	sf::Sprite m_sprite;

};