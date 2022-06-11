#include "SettingsMenu.h"
SettingsMenu::SettingsMenu()
	: Menu(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "SETTINGS", Display(Graphics::getGraphics().getTexture(SETTING_VIEW), sf::Vector2f(0, 0), sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW)))
{
	addCellToVec(std::make_pair(std::move(std::make_unique<ShowInstructions>()), Display(Graphics::getGraphics().getTexture(HELP), sf::Vector2f(10, 10), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));
	addCellToVec(std::make_pair(std::move(std::make_unique<BackSound>()), Display(Graphics::getGraphics().getTexture(INSTRUCTIONS), sf::Vector2f(70, 10), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));
	addCellToVec(std::make_pair(std::move(std::make_unique<Noise>()), Display(Graphics::getGraphics().getTexture(INSTRUCTIONS), sf::Vector2f(130, 10), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));
	// addCellToVec(std::pair(std::make_unique<Scores>(),Display (Graphics::getGraphics().getTexture(EXIT), sf::Vector2f(10, 10), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));
}
