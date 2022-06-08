#pragma once
#include "Level.h"
class InfoOfLevel;
class GameController
{
public:
	GameController() {}
	~GameController() {}
	void runTheGame();
private:
	sf::RenderWindow m_window;
	InfoOfLevel m_infoOfLevel;
};
