#include "SettingsMenu.h"
SettingsMenu::SettingsMenu()
	: Menu(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "SETTINGS", Display(Graphics::getGraphics().getTexture(SETTING_VIEW), sf::Vector2f(0, 0), sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW)))
{
	addCellToVec(std::make_pair(std::move(std::make_unique<ShowInstructions>()), Display(Graphics::getGraphics().getTexture(HELP), sf::Vector2f(500, 100), sf::Vector2f(200, 200))));
	if (Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->getVolume() == 100)
		addCellToVec(std::make_pair(std::move(std::make_unique<BackSound>()), Display(Graphics::getGraphics().getTexture(SOUND), sf::Vector2f(800, 100), sf::Vector2f(200, 200))));
	else
		addCellToVec(std::make_pair(std::move(std::make_unique<BackSound>()), Display(Graphics::getGraphics().getTexture(UN_SOUND), sf::Vector2f(800, 100), sf::Vector2f(200, 200))));
	addCellToVec(std::make_pair(std::move(std::make_unique<Noise>()), Display(Graphics::getGraphics().getTexture(NOISE), sf::Vector2f(1100, 100), sf::Vector2f(200, 200))));
}
