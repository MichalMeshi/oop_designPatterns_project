#pragma once
#include "CanMoveToPlace.h"
#include "EnemyFactory.h"

class MoveToBlocked:public CanMoveToPlace
{
public:
	MoveToBlocked() :CanMoveToPlace() {}
	virtual ~MoveToBlocked() override{}
	virtual bool ableToMoveToPlace()override { return true; }
private:
	static bool m_register;

};
bool MoveToBlocked::m_register = EnemyFactory::registerWhereCanMove(MOVE_TO_BLOCKED, []()->std::unique_ptr<CanMoveToPlace> { return std::make_unique<MoveToBlocked>(); });
