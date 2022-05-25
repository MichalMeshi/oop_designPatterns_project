#include "StartMenu.h"
#include "Command.h"
//-----------------------------------------
StartMenu::StartMenu(GameController& gameCon) : Menu(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "AirXonix", Display(Graphics::getGraphics().getTexture(START_VIEW), sf::Vector2f(0, 0), sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW))) {
	addCellToVec(std::make_pair(std::move(std::make_unique<NewGame>(gameCon)), Display(Graphics::getGraphics().getTexture(PLAY), sf::Vector2f(100, 270), sf::Vector2f(200, 50))));
	addCellToVec(std::make_pair(std::move(std::make_unique<Settings>()), Display(Graphics::getGraphics().getTexture(SETTING), sf::Vector2f(100, 500), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));
}
