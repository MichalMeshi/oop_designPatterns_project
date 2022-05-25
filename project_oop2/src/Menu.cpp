#include "StartMenu.h"
#include "NewGame.h"

void Menu::run()
{
	while (m_window.isOpen())
	{
		handleBoard();
		if (auto event = sf::Event{}; m_window.waitEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed: {
				m_window.close();
				return;
			}
			case sf::Event::MouseButtonReleased: {
				handlePress(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
			}
			}
		}
	}
}
//=====================================================================
//פונקציה המטפלת הניראות הלוח בכל איטרציה
//---------------------------------------
void Menu::handleBoard()
{
	m_window.clear();
	m_View.draw(m_window);
	for (int i = 0; i < m_menu.size(); i++)
		m_menu[i].second.draw(m_window);
	m_window.display();
}
//---------------------------------------------------------------------
void Menu::handlePress(sf::Vector2f press_position)
{
	for (int i = 0; i < m_menu.size(); i++)
	{
		if (m_menu[i].second.getSprite().getGlobalBounds().contains(press_position))
			m_menu[i].first->execute();
	}
}