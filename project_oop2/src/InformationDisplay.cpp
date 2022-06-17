#include "InformationDisplay.h"
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <sstream>
#include <string>
//---------------------------------------------------------------------------------------
InformationDisplay::InformationDisplay(char levelNum,int time)
	:m_clockPicture(Graphics::getGraphics().getTexture(CLOCKPICTURE), CLOCK_ICON_POSITION, sf::Vector2f(100, 100))
	, m_heartPicture(Graphics::getGraphics().getTexture(HEART_ICON), sf::Vector2f(50, 50), sf::Vector2f(60, 60)),m_timeLeftInLevel(time) {
	initializeLevelTxt();
	initializeNumLevelTxt(levelNum);
	initializeTimeLeftTxt();
	initializePercentagLeftTxt();
}
//פונקציה המדפיסה את המידע שבכל שלב
//---------------------------------------------------------------------------------------
void InformationDisplay::drawInfoMenu(int lifeAmount)
{
	float xPos = 50;
	Graphics::getGraphics().getWindow().draw(m_levelTxt);
	m_clockPicture.draw();
	for (int i = 0; i < lifeAmount; i++)
	{
		m_heartPicture.setPosition(sf::Vector2f(xPos, 100));
		m_heartPicture.draw();
		xPos += 40;
	}
	Graphics::getGraphics().getWindow().draw(m_timeLeftTxt);
	Graphics::getGraphics().getWindow().draw(m_percentageTxt);
	Graphics::getGraphics().getWindow().draw(m_numLevelTxt);
}
//פונקציה המעדכנת את הטיימר
//---------------------------------------------------------------------------------------
void InformationDisplay::setTimer(float time)
{
	m_timeLeftInLevel = time;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << time;
	m_timeLeftTxt.setString(stream.str());
}
//פונקציה המעדכנת את האחוזים
//---------------------------------------------------------------------------------------
void InformationDisplay::setPercentage(int percent,int max_per)
{
	std::string per = std::to_string(percent);
	std::string max = std::to_string(max_per);
	m_percentageTxt.setString(per +="% of "+ max +"%");

}
//---------------------------------------------------------------------------------------
void InformationDisplay::initializeLevelTxt()
{
	m_levelTxt.setFont(Graphics::getGraphics().getFont());
	m_levelTxt.setString("LEVEL");
	m_levelTxt.setPosition(50,30);
	m_levelTxt.setCharacterSize(50);
	m_levelTxt.setColor(sf::Color::Black);
}
//---------------------------------------------------------------------------------------
void InformationDisplay::initializePercentagLeftTxt()
{
	m_percentageTxt.setFont(Graphics::getGraphics().getFont());
	m_percentageTxt.setString("%");
	m_percentageTxt.setPosition(1360, 800);
	m_percentageTxt.setCharacterSize(40);
	m_percentageTxt.setColor(sf::Color::Black);
}
//---------------------------------------------------------------------------------------
void InformationDisplay::initializeNumLevelTxt(char nameFile)
{
	m_numLevelTxt.setString(nameFile);
	m_numLevelTxt.setFont(Graphics::getGraphics().getFont());
	m_numLevelTxt.setPosition(160,30);
	m_numLevelTxt.setCharacterSize(50);
	m_numLevelTxt.setColor(sf::Color::Black);
}
//---------------------------------------------------------------------------------------
void InformationDisplay::initializeTimeLeftTxt()
{
	m_timeLeftTxt.setFont(Graphics::getGraphics().getFont());
	m_timeLeftTxt.setString(std::to_string(m_timeLeftInLevel));
	m_timeLeftTxt.setPosition(1415,80);
	m_timeLeftTxt.setCharacterSize(40);
	m_timeLeftTxt.setColor(sf::Color::Black);
}

