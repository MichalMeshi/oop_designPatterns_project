#pragma once
#include "Display.h"
//----------------------------------------------
class Command {
public:
	Command()=default;
	virtual ~Command() = 0{}
	virtual void execute(sf::RenderWindow& window,Display& d) = 0{}
private:
};