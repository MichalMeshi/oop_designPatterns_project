#include "MoveToBlocked.h"
#include "Board.h"
//------------------------------------------------------------
//פונקציה המחזירה האם מותר להתקדם למשבצת הבאה, כלומר האם היא חסומה, 
//------------------------------------------------------------
bool MoveToBlocked::ableToMoveToPlace(sf::Vector2i pos, Board& b)
{
	return (b.checkIfBlocked(pos));
}
