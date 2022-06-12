#pragma once
#include "Display.h"
#include "Board.h"
class InformationMenu
{
public:
	InformationMenu(char ,sf::RenderWindow& window,int);
	~InformationMenu()=default;
	void drawInfoMenu(int life);
	void setTimer(float time);
	void setPercentage(int, int);
	void initializeLevelTxt();
	void initializeNumLevelTxt(char nameFile);
	void initializeTimeLeftTxt();
	void initializePercentagLeftTxt();
	
private:
	float m_timeLeftInLevel; //to be changed
	Display m_heartPicture;
	Display m_clockPicture;
	sf::Text m_timeLeftTxt;
	sf::Text m_levelTxt;
	sf::Text m_numLevelTxt;
	sf::Text m_percentageTxt;
	sf::Vector2f m_firstHeartPosition = FIRST_HEART_POSITION;
	sf::RenderWindow& m_window;
};



