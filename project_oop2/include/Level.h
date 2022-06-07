#pragma once
#include "Board.h"
#include "InformationMenu.h"
class Level{
public:

	Level(sf::RenderWindow& window, int curentLevel);
	~ Level()= default;
	enum EndOfLevelCondition runLevel();
	void reduceLife() { --m_life; m_board.setPlayerPositionToBegining(); }
	void addLife() { m_life++; }
	void addTime() { m_timeForLevel += ((rand() % 5) +6); }
	void freezeEnemies() { m_board.freezeEnemies(); m_clockForGift.restart(); }
private:
	Board m_board;
	sf::RenderWindow& m_window;
	InformationMenu m_infoMenu;
	sf::Clock m_clockForGift;
	int m_timeForLevel;
	int m_life = 3;
};


