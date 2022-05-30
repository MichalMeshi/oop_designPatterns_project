#pragma once
#include "Level.h"
class GameController
{
public:
	GameController() {}
	~GameController() {}
	void runTheGame();
private:
	sf::RenderWindow m_window;
};
