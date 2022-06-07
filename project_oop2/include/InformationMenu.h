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
	void initializeLevelTxt();
	void initializeNumLevelTxt(char nameFile);
	void initializeTimeLeftTxt();
	
private:
	float m_timeLeftInLevel; //to be changed
	int m_percentage=0;
	Display m_heartPicture;
	Display m_clockPicture;
	sf::Text m_timeLeftTxt;
	sf::Text m_levelTxt;
	sf::Text m_numLevelTxt;
	sf::Vector2f m_firstHeartPosition= sf::Vector2f(10,5);
	sf::RenderWindow& m_window;
};



