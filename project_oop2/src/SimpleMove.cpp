
#include "SimpleMove.h"
#include "Board.h"
sf::Vector2f SimpleMove::move(Board& b)
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
	return sf::Vector2f(x, y);
}