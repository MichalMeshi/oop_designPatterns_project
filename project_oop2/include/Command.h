#pragma once
#include "Display.h"
class Command
{
public:
	Command()=default;
	virtual ~Command() = 0{}
	virtual void execute(sf::RenderWindow& window) = 0{}
	virtual void unExecute(sf::RenderWindow& window) = 0{}
private:

};


