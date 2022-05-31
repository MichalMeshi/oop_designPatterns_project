#include "ShowInstructions.h"
#include "Settings.h"

ShowInstructions::ShowInstructions()
	:Command(),m_instructions(Graphics::getGraphics().getTexture(INSTRUCTIONS),
		sf::Vector2f(0, 0), sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW)),
	m_back(Graphics::getGraphics().getTexture(BACK),
		sf::Vector2f(10, 10), sf::Vector2f(100, 70)){}

void ShowInstructions::execute(sf::RenderWindow& window)
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
