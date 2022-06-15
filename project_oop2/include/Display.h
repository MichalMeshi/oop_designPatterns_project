#pragma once
#include "Graphics.h"
//------------------------------------------
class Display{
public:
	Display(const sf::Texture& t, sf::Vector2f position, sf::Vector2f scale);
	Display(const sf::Texture& t,sf::Vector2f scale);
	sf::Sprite getSprite()const { return m_sprite; }
	const sf::Texture* getTexture() { return (m_sprite.getTexture()); }
	void draw(sf::RenderWindow& window) { window.draw(m_sprite); }
	void setPosition(sf::Vector2f v) { m_sprite.setPosition(v); }
	void setOrigin() { m_sprite.setOrigin({15,15/* m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height*/ }); }
	void setOrigin(float x, float y) { m_sprite.setOrigin({x, y}); }
	void setColor(sf::Color c) { m_sprite.setColor(c); }
	void rotate() {  m_sprite.rotate(-10); }
	void setTexture(sf::Texture& t) { m_sprite.setTexture(t); }
	void scale(float x, float y) {m_sprite.setScale(x, y); }
	void update(float posX,int length) { m_sprite.setTextureRect(sf::IntRect(posX, 0, length, length)); }
private:
	sf::Sprite m_sprite;
};