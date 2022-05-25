#pragma once
#include "Display.h"
class Board;
class Object 
{
public:
	Object(sf::Texture& t,sf::Vector2f f1, sf::Vector2f f2):m_display(t,f1,f2) {}
	~Object() = default;
	void draw(sf::RenderWindow& w) { m_display.draw(w); }
	void setPosition(int x, int  y) { m_display.setPosition( x,y ); }

private:
	Display m_display;
	void handleColision();
};