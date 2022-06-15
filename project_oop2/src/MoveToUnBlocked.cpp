#include "MoveToUnBlocked.h"
//פונקציה המחזירה אם מותר לזוז, כלומר במקרה שהמשבצת איננה חסומה
bool MoveToUnBlocked::ableToMoveToPlace(sf::Vector2i pos, Board& b)
{
	return (b.checkIUnfBlocked(pos));
}