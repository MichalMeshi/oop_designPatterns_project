#include "MoveToUnBlocked.h"
bool MoveToUnBlocked::ableToMoveToPlace(sf::Vector2i pos, Board& b)
{
	return (b.checkIUnfBlocked(pos));
}