#include "StartMenu.h"
#include "Command.h"
//-----------------------------------------
StartMenu::StartMenu(GameController& gameCon) : Menu(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "AirXonix", Display(Graphics::getGraphics().getTexture(START_VIEW), sf::Vector2f(0, 0), sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW))) {
	addCellToVec(std::make_pair(std::move(std::make_unique<NewGame>(gameCon)), Display(Graphics::getGraphics().getTexture(PLAY), sf::Vector2f(780, 600), sf::Vector2f(500, 120))));
	addCellToVec(std::make_pair(std::move(std::make_unique<Settings>()), Display(Graphics::getGraphics().getTexture(SETTING), sf::Vector2f(780, 750), sf::Vector2f(500, 120))));
	m_menu[0].second.setOrigin(250,60);
	m_menu[1].second.setOrigin(250,60);
}

