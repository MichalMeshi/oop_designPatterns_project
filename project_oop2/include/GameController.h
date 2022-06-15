#pragma once
#include "Level.h"
class InfoOfLevel;
class GameController
{
public:
	GameController():m_winGame(Graphics::getGraphics().getTexture(WIN_GAME), sf::Vector2f(800, 500), sf::Vector2f(800, 500)),
		m_gameOver(Graphics::getGraphics().getTexture(GAME_OVER), sf::Vector2f(800, 500), sf::Vector2f(500, 150))
	{
		m_winGame.setOrigin(400,250);
		m_gameOver.setOrigin(250,75);
	}
	~GameController() {}
	void runTheGame();
private:
	sf::RenderWindow m_window;
	InfoOfLevel m_infoOfLevel;
	Display m_winGame;
	Display m_gameOver;
};
