#pragma once
#include "Command.h"
//-----------------------------------
class BackSoundCommand:public Command {
public:
	BackSoundCommand() :Command() {}
	~BackSoundCommand() = default;
	virtual void execute(sf::RenderWindow& window, Display&) override;
private:
};
