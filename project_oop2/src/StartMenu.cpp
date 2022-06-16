#include "StartMenu.h"
#include "Command.h"
//-----------------------------------------
StartMenu::StartMenu(GameController& gameCon) : Menu(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "AirXonix", Display(Graphics::getGraphics().getTexture(START_VIEW), BEGGINING_WINDOW, sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW))) {
	addCellToVec(std::make_pair(std::move(std::make_unique<NewGameCommand>(gameCon)), Display(Graphics::getGraphics().getTexture(PLAY), NEW_GAME_POS, NEW_GAME_SIZE)));
	addCellToVec(std::make_pair(std::move(std::make_unique<SettingsCommand>()), Display(Graphics::getGraphics().getTexture(SETTING), SETTINGS_POS, SETTING_SIZE)));
	m_menu[0].second.setOrigin(NEW_GAME_SIZE.x/2, NEW_GAME_SIZE.y / 2);
	m_menu[1].second.setOrigin(SETTING_SIZE.x/2, SETTING_SIZE.y / 2);
}

