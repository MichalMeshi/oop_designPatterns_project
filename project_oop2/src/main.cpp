#include "Controller.h"
//---------------------------
int main()try
{
	srand(static_cast<unsigned>(time(nullptr)));
	Controller c;
	c.run();
	return EXIT_SUCCESS;
}
//---------------------------
catch (std::exception& e)
{
	sf::Text error;
	if (Graphics::getGraphics().getWindow().isOpen())
	{
		error.setFont(Graphics::getGraphics().getFont());
		error.setString(e.what());
		Graphics::getGraphics().getWindow().clear();
		Graphics::getGraphics().getWindow().draw(error);
		Graphics::getGraphics().getWindow().display();
		sf::sleep(sf::Time(sf::seconds(THREE_SECONDS)));
		Graphics::getGraphics().getWindow().close();
	}
	return EXIT_FAILURE;
}