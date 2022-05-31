#include "MoveToBlocked.h"
#include "Board.h"

bool MoveToBlocked::ableToMoveToPlace(sf::Vector2i pos, Board& b)
{
	return (b.checkIfBlocked(pos));
}
