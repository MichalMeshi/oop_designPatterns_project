#pragma once
#include "Enemies.h"
class Move;
class Level;
class CanMoveToPlace;
typedef std::unique_ptr<Move>(*moveFunc)(sf::Vector2i,std::unique_ptr<CanMoveToPlace>);
typedef std::unique_ptr<CanMoveToPlace>(*WhereCanMoveFunc)();
class EnemyFactory
{
public:
	static std::vector<moveFunc>& getMoveVec();
	static std::vector<WhereCanMoveFunc>& getWhereCanMoveVec();
	static bool registerMove(enum MoveEnum e, moveFunc mf);
	static bool registerWhereCanMove(enum WhereCanMoveEnum e, WhereCanMoveFunc sf);
	static std::unique_ptr<Enemies> createEnemy(sf::Vector2i ,sf::Texture& t, sf::Vector2f f, enum MoveEnum e_move, enum WhereCanMoveEnum e_whereMove, Level*);
	static std::vector<std::unique_ptr<Enemies>> createEnemies(int level_num,Level*);
private:
	//לחשוב איפה לשים את המטריצה של כל האנמיז
};