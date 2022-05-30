#pragma once
#include "Command.h"
class ShowInstructions:public Command
{

public:
	ShowInstructions();
	~ShowInstructions() = default;
	virtual void execute(sf::RenderWindow& window) override;
	void draw(sf::RenderWindow& window) {m_instructions.draw(window); m_back.draw(window);}
private:
	Display m_instructions;
	Display m_back;
};
