#pragma once
#include "Board.h"
#include "InformationMenu.h"
class Level{
public:

	Level(sf::RenderWindow& window, int curentLevel);
	~ Level()= default;
	enum EndOfLevelCondition runLevel();
	void reduceLife() { --m_life; }
private:
	Board m_board;
	sf::RenderWindow& m_window;
	InformationMenu m_infoMenu;
	int m_timeForLevel;
	int m_life = 3;
};


