#pragma once
#include "CanMoveToPlace.h"
#include "EnemyFactory.h"
#include "Board.h"
//-----------------------------------------------
class MoveToUnBlocked :public CanMoveToPlace{
public:
	MoveToUnBlocked() :CanMoveToPlace() {}
	virtual ~MoveToUnBlocked() override {}
	virtual bool ableToMoveToPlace(sf::Vector2i , Board& )override;
private:
	static bool m_register;
};
bool MoveToUnBlocked::m_register = EnemyFactory::registerWhereCanMove(MOVE_TO_UNBLOCKED, []()->std::unique_ptr<CanMoveToPlace> { return std::make_unique<MoveToUnBlocked>(); });
