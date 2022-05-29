#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities.h"

class Board;
class Move{
public:
	Move() {}
	virtual ~Move()=0{}
	virtual sf::Vector2f move(Board& b) = 0{}
	sf::Vector2i getIndex()const { return sf::Vector2i((y - 50) / 20, (x - 350) / 20); }

protected:
	int x = 500, y = 500;
	int dx = 4 - rand() % 8;
	int dy = 4 - rand() % 8;
};