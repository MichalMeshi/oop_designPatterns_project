#pragma once
#include "Level.h"
class InfoOfLevel;
class GameController
{
public:
	GameController():m_gameOver(Graphics::getGraphics().getTexture(GAME_OVER), MIDDLE_MATRIX, GAME_OVER_SIZE)
	{
		m_gameOver.setOrigin(GAME_OVER_SIZE.x/2, GAME_OVER_SIZE.y /2);
	}
	~GameController() {}
	void runTheGame();
private:
	InfoOfLevel m_infoOfLevel;
	Display m_gameOver;
	void handleWindow();
	void runGameLevels(int&);

};
