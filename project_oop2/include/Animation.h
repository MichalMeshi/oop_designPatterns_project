#pragma once
#include "Display.h"
class Animaton
{
public:
	Animaton(Display& display):m_display(display){}
private:
	Display& m_display;

};