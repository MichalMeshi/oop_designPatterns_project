#pragma once
#include "Display.h"
#include "Board.h"
class InformationDisplay
{
public:
	InformationDisplay(char ,int);
	~InformationDisplay()=default;
	void drawInfoMenu(int life);
	void setTimer(float time);
	void setPercentage(int, int);
	void initializeLevelTxt();
	void initializeNumLevelTxt(char nameFile);
	void initializeTimeLeftTxt();
	void initializePercentagLeftTxt();
private:
	float m_timeLeftInLevel;
	Display m_heartPicture;
	Display m_clockPicture;
	sf::Text m_timeLeftTxt;
	sf::Text m_levelTxt;
	sf::Text m_numLevelTxt;
	sf::Text m_percentageTxt;
	sf::Vector2f m_firstHeartPosition = FIRST_HEART_POSITION;
};



