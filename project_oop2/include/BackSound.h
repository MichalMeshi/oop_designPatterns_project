#pragma once
#include "Command.h"
class BackSound:public Command {
public:
	BackSound() :Command() {}
	~BackSound() = default;
	virtual void execute(sf::RenderWindow& window, Display&) override;
private:
};
