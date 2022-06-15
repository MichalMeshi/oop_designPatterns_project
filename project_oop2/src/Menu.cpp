#include "StartMenu.h"
#include "NewGameCommand.h"

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
			case sf::Event::MouseMoved: {
				handleMouseMove(m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }));
				break;
			}
			}
		}
	}
}
//-------------------------------------------------------------
void  Menu::handleMouseMove(sf::Vector2f move_position)
{
	for (int i = 0; i < m_menu.size(); i++)
	{
		if (m_menu[i].second.getSprite().getGlobalBounds().contains(move_position))
			m_menu[i].second.scale(1.3,1.3);
		else
			m_menu[i].second.scale(1, 1);
	}
}
//=====================================================================
//פונקציה המטפלת בניראות הלוח בכל איטרציה
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
		if (m_menu[i].second.getSprite().getGlobalBounds().contains(press_position))
		{
			Graphics::getGraphics().getSoundVec()[CLICK_SOUND]->play();
			m_menu[i].first->execute(m_window, m_menu[i].second);
		}
}
