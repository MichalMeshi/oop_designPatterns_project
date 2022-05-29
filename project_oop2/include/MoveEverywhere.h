#pragma once
#include "CanMoveToPlace.h"
#include "EnemyFactory.h"

class MoveEverywhere :public CanMoveToPlace
{
public:
	MoveEverywhere():CanMoveToPlace(){}
	virtual ~MoveEverywhere() override {}
	virtual bool ableToMoveToPlace()override { return true; }
private:
	static bool m_register;

};
bool MoveEverywhere::m_register = EnemyFactory::registerWhereCanMove(MOVE_EVERYWHERE, []()->std::unique_ptr<CanMoveToPlace> { return std::make_unique<MoveEverywhere>(); });
