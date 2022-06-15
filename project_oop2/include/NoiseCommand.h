#pragma once
#include "Command.h"
class NoiseCommand :public Command {
public:
	NoiseCommand() :Command() {}
	~NoiseCommand() = default;
	virtual void execute(sf::RenderWindow& window, Display& d) override;
};
