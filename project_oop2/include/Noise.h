#pragma once
#include "Command.h"
class Noise :public Command {
public:
	Noise() :Command() {}
	~Noise() = default;
	virtual void execute(sf::RenderWindow& window, Display& d) override;
private:
};
