#include "ShowInstructionsCommand.h"
#include "SettingsCommand.h"

ShowInstructionsCommand::ShowInstructionsCommand()
	:Command(),m_instructions(Graphics::getGraphics().getTexture(INSTRUCTIONS),
		BEGGINING_WINDOW, sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW)),
	m_back(Graphics::getGraphics().getTexture(BACK), BEGGINING_WINDOW, BACK_BOTTON_SIZE){}
//פונקציה האחראית על ביצוע הפקודה של הדפסת הוראות המשחק
void ShowInstructionsCommand::execute(Display& d)
{
	while (Graphics::getGraphics().getWindow().isOpen())
	{
		Graphics::getGraphics().getWindow().clear();
		draw();
		Graphics::getGraphics().getWindow().display();
		if (auto event = sf::Event{}; Graphics::getGraphics().getWindow().waitEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed: {
				Graphics::getGraphics().getWindow().close();
				return;
			}
			case sf::Event::MouseButtonReleased: 
			{
				if(m_back.getSprite().getGlobalBounds().contains(Graphics::getGraphics().getWindow().mapPixelToCoords( { event.mouseButton.x, event.mouseButton.y })))
				return;
			}
			}
		}
	}
}
