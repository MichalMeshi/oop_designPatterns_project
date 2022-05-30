#pragma once
#include "Board.h"
#include "InformationMenu.h"
class Level
{
public:
	Level(sf::RenderWindow& window, int curentLevel);
	~ Level()= default;
	enum EndOfLevelCondition runLevel();
private:
	Board m_board;
	sf::RenderWindow& m_window;
	InformationMenu m_infoMenu;
};


