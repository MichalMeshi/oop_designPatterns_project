#include "Ball.h"
#include "Board.h"
bool Ball::move(Board& b) 
{
	x += dx; 
	if (b.checkIfMatCellEqualTo(sf::Vector2i((y - 50) / 20, (x - 350) / 20), BLOCKED))
	{
		dx = -dx; 
		x += dx;
	}
	y += dy; 
	if (b.checkIfMatCellEqualTo(sf::Vector2i((y - 50) / 20, (x - 350) / 20), BLOCKED))
	{ 
		dy = -dy; 
		y += dy; 
	}
	return false;
}