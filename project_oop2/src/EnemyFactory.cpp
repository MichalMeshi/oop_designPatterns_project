#include "EnemyFactory.h"

 std::vector<moveFunc>& EnemyFactory::getMoveVec()
{
	static std::vector<moveFunc> m_moveVec(E_MOVE_MAX_SIZE);
	return m_moveVec;
}
 std::vector<WhereCanMoveFunc>& EnemyFactory::getWhereCanMoveVec()
{
	static std::vector<WhereCanMoveFunc> m_whereCanMove(E_WHERE_CAN_MOVE_MAX_SIZE);
	return m_whereCanMove;
}

 bool EnemyFactory::registerMove(enum MoveEnum e, moveFunc mf)
{
	getMoveVec()[e] = std::move(mf);
	return true;
}
 bool EnemyFactory::registerWhereCanMove(enum WhereCanMoveEnum e, WhereCanMoveFunc sf)
{
	getWhereCanMoveVec()[e] = std::move(sf);
	return true;
}

 std::unique_ptr<Enemies> EnemyFactory::createEnemy(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2, enum MoveEnum e_move, enum WhereCanMoveEnum e_whereMove)
{
	return std::make_unique<Enemies>(t, f1, f2,getMoveVec()[e_move](), getWhereCanMoveVec()[e_whereMove]());
}
