#pragma once
#include "Command.h"
class ShowInstructionsCommand:public Command
{

public:
	ShowInstructionsCommand();
	~ShowInstructionsCommand() = default;
	virtual void execute(sf::RenderWindow& window, Display& d) override;
	void draw(sf::RenderWindow& window) {m_instructions.draw(window); m_back.draw(window);}
private:
	Display m_instructions;
	Display m_back;
};
