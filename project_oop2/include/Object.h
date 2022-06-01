#pragma once
#include "Display.h"
class Object
{
public:
	Object(sf::Texture& t, sf::Vector2f f) :m_display(t, f) {}
	virtual ~Object() = 0{}
	void draw(sf::RenderWindow& w) { m_display.draw(w); }
	void setPosition(sf::Vector2f v) { m_display.setPosition(v); }
	Display& getDisplay() { return m_display; };
protected:
	Display m_display;
	void handleColision();
};