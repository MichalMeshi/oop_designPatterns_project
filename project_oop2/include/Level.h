#pragma once
#include "Board.h"
#include "InformationDisplay.h"
#include "InfoOfLevel.h"
//-----------------------------------------------
class Level{
public:
	Level(int curentLevel, std::vector<int>);
	~ Level()= default;
	void addLife() { m_infoOfLevel[LIFE_AMOUNT]++; }
	void addTime() { m_timeForLevel += (rand() % FIVE) + SEVEN; }
	void freezeEnemies() {m_board.freezeEnemies(); restartClockForGift();}
	void restartClockForGift(){ m_clockForGift.restart(); }
	int getPercentage()const { return m_percentage; }
	void setPercentage(int percent) {  m_percentage= percent; }
	void handleAnimationExplosion();
	void drawWindow();
	void immuneThePlayer(){m_board.immuneThePlayer();}
	void changePlayerToKilling() { m_board.changePlayerToKilling(); }
	void updateFailure(bool b) { m_board.updateFailure(b); }
	enum EndOfLevelCondition runLevel();
	void handleFailure();
private:
	Board m_board;
	InformationDisplay m_infoMenu;
	sf::Clock m_clockForGift;
	sf::Clock m_clock;
	int m_timeForLevel;
	int m_percentage = ZERO;
	std::vector<int> m_infoOfLevel;
	Display m_explosionPic;
	Display m_winGame;
	Animation m_explosionAnimation;
	Display m_levelUp;
	int m_gift_num = (rand() % AMOUNT_OF_GIFTS) + AMOUNT_OF_GIFTS;
	int m_rand_time = (rand() % SIX) + FIVE;
	int m_currentLevel;

	enum EndOfLevelCondition handleEvents();
	void handleTime();
	void movesObjects();
	enum EndOfLevelCondition handlePercentage();
	void handlePlayer();
};


