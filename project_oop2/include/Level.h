#pragma once
#include "Board.h"
#include "InformationMenu.h"
#include "InfoOfLevel.h"

class Level{
public:

	Level(sf::RenderWindow& window, int curentLevel, std::vector<int>);
	~ Level()= default;
	enum EndOfLevelCondition runLevel();
	void reduceLife() { --m_life; m_board.setPlayerPositionToBegining(); }
	void addLife() { m_life++; }
	void addTime() { m_timeForLevel += ((rand() % 5) +6); }
	void freezeEnemies() { m_board.freezeEnemies(); m_clockForGift.restart(); }
	int getPercentage()const { return m_percentage; }
	void setPercentage(int percent) {  m_percentage= percent; }
private:
	Board m_board;
	sf::RenderWindow& m_window;
	InformationMenu m_infoMenu;
	sf::Clock m_clockForGift;
	int m_timeForLevel;
	int m_life = 3;
	int m_percentage = 8;
	std::vector<int> m_infoOfLevel;
};


