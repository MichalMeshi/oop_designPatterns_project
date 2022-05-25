#pragma once
#include "Board.h"
class Level
{
public:
	 Level(sf::RenderWindow& window);
	~ Level()= default;
	void runLevel();
private:
	Board m_board;
	sf::RenderWindow& m_window;
};


