#include "ShowInstructions.h"
#include "Settings.h"
void ShowInstructions::execute()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "HELP");
	while (window.isOpen())
	{
		window.clear();
		drawInstructions(window);
		window.display();
		if (auto event = sf::Event{}; window.waitEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed: {
				window.close();
				return;
			}
			}
		}
	}
}