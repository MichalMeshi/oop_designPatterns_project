#include "SettingsMenu.h"
SettingsMenu::SettingsMenu(sf::RenderWindow& w)
	: Menu(w,Display (Graphics::getGraphics().getTexture(SETTING_VIEW), sf::Vector2f(0, 0), sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW))), m_back(Graphics::getGraphics().getTexture(BACK),
		sf::Vector2f(10, 100), sf::Vector2f(100, 70))
{
	addCellToVec(std::make_pair(std::move(std::make_unique<ShowInstructions>()), Display(Graphics::getGraphics().getTexture(HELP), sf::Vector2f(10, 10), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));
//	addCellToVec(std::pair(std::make_unique<Scores>(),Display (Graphics::getGraphics().getTexture(EXIT), sf::Vector2f(10, 10), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));
//	addCellToVec(std::pair(std::make_unique<Noise>(),Display (Graphics::getGraphics().getTexture(EXIT), sf::Vector2f(10, 10), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));
//	addCellToVec(std::pair(std::make_unique<BackSound>(), Display(Graphics::getGraphics().getTexture(EXIT), sf::Vector2f(10, 10), sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE))));

}
void SettingsMenu::handleBoard()
{
	m_window.clear();
	m_View.draw(m_window);
	for (int i = 0; i < m_menu.size(); i++)
		m_menu[i].second.draw(m_window);
	m_back.draw(m_window);
	m_window.display();
}

