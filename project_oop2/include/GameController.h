#pragma once
#include "Level.h"
class InfoOfLevel;
class GameController{
public:
	GameController();
	~GameController() {}
	void runTheGame();
private:
	InfoOfLevel m_infoOfLevel;
	Display m_gameOver;
	void runGameLevels(int&);
};
