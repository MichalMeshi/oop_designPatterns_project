#pragma once
#include "Command.h"
class Noise :public Command {
public:
	Noise() :Command() {}
	~Noise() = default;
	virtual void execute(sf::RenderWindow& window) override;
	virtual void unExecute(sf::RenderWindow& window) override;


private:
};
