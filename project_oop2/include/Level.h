#pragma once
#include "Board.h"
#include "InformationMenu.h"
#include "InfoOfLevel.h"

class Level{
public:

	Level(sf::RenderWindow& window, int curentLevel, std::vector<int>);
	~ Level()= default;
	enum EndOfLevelCondition runLevel();
	void reduceLife() { --m_infoOfLevel[LIFE_AMOUNT]; m_board.setPlayerPositionToBegining(); }
	void addLife() { m_infoOfLevel[LIFE_AMOUNT]++; }
	void addTime() { m_timeForLevel += ((rand() % 5) +6); }
	void freezeEnemies() { m_board.freezeEnemies(); m_clockForGift.restart(); }
	int getPercentage()const { return m_percentage; }
	void setPercentage(int percent) {  m_percentage= percent; }
	void handleAnimationExplosion();
	void drawing();

private:
	Board m_board;
	sf::RenderWindow& m_window;
	InformationMenu m_infoMenu;
	sf::Clock m_clockForGift;
	int m_timeForLevel;
	int m_percentage = 0;
	std::vector<int> m_infoOfLevel;
	Display m_explosionAnimation;
	sf::Vector2f m_animationPos;
};


