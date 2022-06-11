#include "InformationMenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <sstream>
#include <string>

//---------------------------------------------------------------------------------------
InformationMenu::InformationMenu(char levelNum, sf::RenderWindow& window,int time)
	:m_window(window), m_clockPicture(Graphics::getGraphics().getTexture(CLOCKPICTURE), CLOCK_ICON_POSITION, sf::Vector2f(60, 60))
	, m_heartPicture(Graphics::getGraphics().getTexture(HEART), sf::Vector2f(20, 200), sf::Vector2f(60, 60)),m_timeLeftInLevel(time) {
	initializeLevelTxt();
	initializeNumLevelTxt(levelNum);
	initializeTimeLeftTxt();
	initializePercentagLeftTxt();
}
//---------------------------------------------------------------------------------------
void InformationMenu::drawInfoMenu(int lifeAmount)
{
	float xPos = 20;
    m_window.draw(m_levelTxt);
	m_clockPicture.draw(m_window);
	for (int i = 0; i < lifeAmount; i++)
	{

		m_heartPicture.setPosition(sf::Vector2f(xPos, 200));
		m_heartPicture.draw(m_window);
		xPos += 40;
	}
	m_window.draw(m_timeLeftTxt);
	m_window.draw(m_percentageTxt);
	m_window.draw(m_numLevelTxt);
}
//---------------------------------------------------------------------------------------
void InformationMenu::setTimer(float time)
{
	m_timeLeftInLevel = time;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << time;
	m_timeLeftTxt.setString(stream.str());
}
//---------------------------------------------------------------------------------------
void InformationMenu::setPercentage(int percent)
{
	std::string per = std::to_string(percent);
	m_percentageTxt.setString(per +="%");

}
//---------------------------------------------------------------------------------------
void InformationMenu::initializeLevelTxt()
{
	m_levelTxt.setFont(Graphics::getGraphics().getFont());
	m_levelTxt.setString("LEVEL");
	m_levelTxt.setPosition(20,5);
	m_levelTxt.setCharacterSize(40);
	m_levelTxt.setColor(sf::Color::Black);
}
//---------------------------------------------------------------------------------------
void InformationMenu::initializePercentagLeftTxt()
{
	m_percentageTxt.setFont(Graphics::getGraphics().getFont());
	m_percentageTxt.setString("%");
	m_percentageTxt.setPosition(20, 100);
	m_percentageTxt.setCharacterSize(40);
	m_percentageTxt.setColor(sf::Color::Black);
}
//---------------------------------------------------------------------------------------
void InformationMenu::initializeNumLevelTxt(char nameFile)
{
	m_numLevelTxt.setString(nameFile);
	m_numLevelTxt.setFont(Graphics::getGraphics().getFont());
	m_numLevelTxt.setPosition(100,5);
	m_numLevelTxt.setCharacterSize(50);
	m_numLevelTxt.setColor(sf::Color::Black);
}
//---------------------------------------------------------------------------------------
void InformationMenu::initializeTimeLeftTxt()
{
	m_timeLeftTxt.setFont(Graphics::getGraphics().getFont());
	m_timeLeftTxt.setString(std::to_string(m_timeLeftInLevel));
	m_timeLeftTxt.setPosition(20,30);
	m_timeLeftTxt.setCharacterSize(40);
	m_timeLeftTxt.setColor(sf::Color::Black);
}

