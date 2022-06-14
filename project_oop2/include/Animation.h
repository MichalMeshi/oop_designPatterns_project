#pragma once
#include "Display.h"
class Animation
{
public:
	Animation(Display& display,int num,int sizePic):m_display(display), m_sizeOfSpriteSheet(num), m_spriteSize(sizePic) {}
	void handleAnimation() {
		m_display.update(m_pos.x, m_spriteSize);
		m_pos.x += m_spriteSize;
		if (m_pos.x == m_sizeOfSpriteSheet)
			m_pos.x = 0;
	}
private:
	Display& m_display;
	sf::Vector2i m_pos = { 0,0 };
	int m_sizeOfSpriteSheet;
	int m_spriteSize;
};