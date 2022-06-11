#pragma once
#include "Command.h"
class BackSound:public Command {
public:
	BackSound() :Command() {}
	~BackSound() = default;
	virtual void execute(sf::RenderWindow& window) override;
	virtual void unExecute(sf::RenderWindow& window) override;
private:
};
