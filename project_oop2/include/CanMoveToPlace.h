#pragma once
#include "Utilities.h"
class Board;
//----------------------------------------------
class CanMoveToPlace{
public:
	CanMoveToPlace() = default;
	virtual ~CanMoveToPlace()=0{}
	virtual bool ableToMoveToPlace(sf::Vector2i pos, Board& b) = 0 { return true; }
};