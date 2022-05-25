#pragma once
#include "Command.h"
class ShowInstructions:public Command
{

public:
	ShowInstructions()
		: Command(),m_instructions(Graphics::getGraphics().getTexture(INSTRUCTIONS), sf::Vector2f(0, 0),sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW)) {}
	~ShowInstructions() = default;
	virtual void execute() override;
	void drawInstructions(sf::RenderWindow& window) { m_instructions.draw(window); }
private:
	Display m_instructions;
};
