#include "Controller.h"
//---------------------------------
void Controller::run() 
{
	sf::RenderWindow w;
	w.create(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "Xonix");
	StartMenu m(m_gameController,w);
	m.run();
}