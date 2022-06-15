#pragma once
#include "Level.h"
class InfoOfLevel;
class GameController
{
public:
	GameController():m_winGame(Graphics::getGraphics().getTexture(WIN_GAME), MIDDLE_MATRIX, MIDDLE_MATRIX),
		m_gameOver(Graphics::getGraphics().getTexture(GAME_OVER), MIDDLE_MATRIX, GAME_OVER_SIZE)
	{
		m_winGame.setOrigin(MIDDLE_MATRIX.x, MIDDLE_MATRIX.y);
		m_gameOver.setOrigin(GAME_OVER_SIZE.x/2, GAME_OVER_SIZE.y /2);
	}
	~GameController() {}
	void runTheGame();
private:
	sf::RenderWindow m_window;
	InfoOfLevel m_infoOfLevel;
	Display m_winGame;
	Display m_gameOver;

	void handleWindow();
	void runGameLevels(int&);

};
