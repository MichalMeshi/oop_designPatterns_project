#pragma once
#include "Enemies.h"
class Move;
class CanMoveToPlace;
typedef std::unique_ptr<Move>(*moveFunc)();
typedef std::unique_ptr<CanMoveToPlace>(*WhereCanMoveFunc)();
class EnemyFactory
{
public:
	static std::vector<moveFunc>& getMoveVec();
	static std::vector<WhereCanMoveFunc>& getWhereCanMoveVec();
	static bool registerMove(enum MoveEnum e, moveFunc mf);
	static bool registerWhereCanMove(enum WhereCanMoveEnum e, WhereCanMoveFunc sf);
	static std::unique_ptr<Enemies> createEnemy(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2, enum MoveEnum e_move, enum WhereCanMoveEnum e_whereMove);

};