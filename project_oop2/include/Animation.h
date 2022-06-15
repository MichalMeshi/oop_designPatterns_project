#pragma once
#include "Display.h"
//-----------------------------------
class Animation
{
public:
	Animation(Display& display,int num,int sizePic):m_display(display), m_sizeOfSpriteSheet(num), m_spriteSize(sizePic) {}
	void handleAnimation();
private:
	Display& m_display;
	sf::Vector2i m_pos = { ZERO,ZERO };
	int m_sizeOfSpriteSheet;
	int m_spriteSize;
};