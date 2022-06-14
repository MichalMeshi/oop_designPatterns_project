#pragma once
#include "Level.h"
class InfoOfLevel;
class GameController
{
public:
	GameController() :m_levelUp(Graphics::getGraphics().getTexture(LEVEL_UP), sf::Vector2f(800, 500), sf::Vector2f(500, 150)) { m_levelUp.setOrigin(250,75); }
	~GameController() {}
	void runTheGame();
private:
	sf::RenderWindow m_window;
	InfoOfLevel m_infoOfLevel;
	Display m_levelUp;
};
