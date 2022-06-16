#include "StartMenu.h"
#include "NewGameCommand.h"
//-------------------------------------------------------------
//פונקציה המנהלת את תוזת העכבר על התפריט
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
	m_View.draw();
	for (int i = 0; i < m_menu.size(); i++)
		m_menu[i].second.draw();
}
//פונקציה המנהלת את כל הקשור בלחיצות על כפתורי התפריט
//---------------------------------------------------------------------
void Menu::handlePress(sf::Vector2f press_position)
{
	for (int i = 0; i < m_menu.size(); i++)
		if (m_menu[i].second.getSprite().getGlobalBounds().contains(press_position))
		{
			Graphics::getGraphics().getSoundVec()[CLICK_SOUND]->play();
			m_menu[i].first->execute(m_menu[i].second);
		}
}
