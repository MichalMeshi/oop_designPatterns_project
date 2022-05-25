#pragma once
#include "Level.h"
class GameController
{
public:
	GameController()=default;
	~GameController()= default;
	void runTheGame();
private:
	sf::RenderWindow m_window;
	//char m_nameFile[10] = { 'l','e','v','e','l',' ','.','t','x','t' };
};
