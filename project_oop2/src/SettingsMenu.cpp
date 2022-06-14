#include "SettingsMenu.h"
SettingsMenu::SettingsMenu()
	: Menu(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "SETTINGS", Display(Graphics::getGraphics().getTexture(SETTING_VIEW), sf::Vector2f(0, 0), sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW)))
{
	addCellToVec(std::make_pair(std::move(std::make_unique<ShowInstructions>()), Display(Graphics::getGraphics().getTexture(HELP), sf::Vector2f(600, 400), sf::Vector2f(200, 200))));
	if (Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->getVolume() == 100)
		addCellToVec(std::make_pair(std::move(std::make_unique<BackSound>()), Display(Graphics::getGraphics().getTexture(SOUND), sf::Vector2f(800, 400), sf::Vector2f(200, 200))));
	else
		addCellToVec(std::make_pair(std::move(std::make_unique<BackSound>()), Display(Graphics::getGraphics().getTexture(UN_SOUND), sf::Vector2f(800, 400), sf::Vector2f(200, 200))));
	if (Graphics::getGraphics().getSoundVec()[CLICK_SOUND]->getVolume() == 100)
		addCellToVec(std::make_pair(std::move(std::make_unique<Noise>()), Display(Graphics::getGraphics().getTexture(NOISE), sf::Vector2f(1000, 400), sf::Vector2f(200, 200))));
	else
		addCellToVec(std::make_pair(std::move(std::make_unique<Noise>()), Display(Graphics::getGraphics().getTexture(UN_NOISE), sf::Vector2f(1000, 400), sf::Vector2f(200, 200))));
	m_menu[0].second.setOrigin(100, 100);
	m_menu[1].second.setOrigin(100, 100);
	m_menu[2].second.setOrigin(100, 100);

}
