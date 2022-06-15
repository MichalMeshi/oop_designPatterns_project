#include "ShowInstructionsCommand.h"
#include "SettingsCommand.h"

ShowInstructionsCommand::ShowInstructionsCommand()
	:Command(),m_instructions(Graphics::getGraphics().getTexture(INSTRUCTIONS),
		BEGGINING_WINDOW, sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW)),
	m_back(Graphics::getGraphics().getTexture(BACK), BEGGINING_WINDOW, BACK_BOTTON_SIZE){}
//פונקציה האחראית על ביצוע הפקודה של הדפסת הוראות המשחק
void ShowInstructionsCommand::execute(sf::RenderWindow& window, Display& d)
{
	while (window.isOpen())
	{
		window.clear();
		draw(window);
		window.display();
		if (auto event = sf::Event{}; window.waitEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed: {
				window.close();
				return;
			}
			case sf::Event::MouseButtonReleased: 
			{
				if(m_back.getSprite().getGlobalBounds().contains(window.mapPixelToCoords( { event.mouseButton.x, event.mouseButton.y })))
				return;
			}
			}
		}
	}
}
