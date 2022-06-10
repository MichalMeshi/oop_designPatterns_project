#pragma once
#include "Enemies.h"
#include "TerritoryEater.h"
class Move;
class Level;
class CanMoveToPlace;
typedef std::shared_ptr<Move>(*moveFunc)(sf::Vector2i, std::unique_ptr<CanMoveToPlace>);
typedef std::unique_ptr<CanMoveToPlace>(*WhereCanMoveFunc)();
class EnemyFactory
{
public:
	static std::vector<moveFunc>& getMoveVec();
	static std::vector<WhereCanMoveFunc>& getWhereCanMoveVec();
	static bool registerMove(enum MoveEnum e, moveFunc mf);
	static bool registerWhereCanMove(enum WhereCanMoveEnum e, WhereCanMoveFunc sf);
	static std::unique_ptr<Enemies> createEnemy(sf::Vector2i, sf::Texture& t, sf::Vector2f f, enum MoveEnum e_move, enum WhereCanMoveEnum e_whereMove, Level*);
	static std::vector<std::unique_ptr<Enemies>> createEnemies(int level_num, Level*, std::vector<int> vec);
	static std::unique_ptr<TerritoryEater> createTerritoryEater(sf::Vector2i pos, sf::Texture& t, sf::Vector2f f, enum MoveEnum e_move, enum WhereCanMoveEnum e_whereMove, Level* l);
	static std::vector<std::unique_ptr<TerritoryEater>> createTerritoryEaters(int level_num, Level* l, std::vector<int> v);
private:
	//לחשוב איפה לשים את המטריצה של כל האנמיז
};