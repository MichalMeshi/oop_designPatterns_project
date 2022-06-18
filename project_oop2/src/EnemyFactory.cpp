#include "EnemyFactory.h"
#include "TerritoryEater.h"
#include "Level.h"
//------------------------------------------------------------
std::vector<moveFunc>& EnemyFactory::getMoveVec()
{
	static std::vector<moveFunc> m_moveVec(E_MOVE_MAX_SIZE);
	return m_moveVec;
}
//------------------------------------------------------------
std::vector<WhereCanMoveFunc>& EnemyFactory::getWhereCanMoveVec()
{
	static std::vector<WhereCanMoveFunc> m_whereCanMove(E_WHERE_CAN_MOVE_MAX_SIZE);
	return m_whereCanMove;
}
//------------------------------------------------------------
bool EnemyFactory::registerMove(enum MoveEnum e, moveFunc mf)
{
	getMoveVec()[e] = std::move(mf);
	return true;
}
//------------------------------------------------------------
bool EnemyFactory::registerWhereCanMove(enum WhereCanMoveEnum e, WhereCanMoveFunc sf)
{
	getWhereCanMoveVec()[e] = std::move(sf);
	return true;
}
//----------------------------------------------------------------------------------------------

std::unique_ptr<Enemies> EnemyFactory::createEnemy(sf::Vector2i pos, sf::Texture& t, enum MoveEnum e_move, enum WhereCanMoveEnum e_whereMove, Level* l)
{
	return std::make_unique<Enemies>(t, getMoveVec()[e_move](pos, getWhereCanMoveVec()[e_whereMove]()), l);
}
//----------------------------------------------------------------------------------------------
std::vector<std::unique_ptr<Enemies>> EnemyFactory::createBalls(int level_num, Level* l)
{
	int num = (rand() % 5) + (level_num+1);
	std::vector<std::unique_ptr<Enemies>> vec;
	for (int i = 0; i < num; i++)
		vec.emplace_back(EnemyFactory::createEnemy(sf::Vector2i(800, 500), Graphics::getGraphics().getTexture(BALL), SIMPLE_MOVE, MOVE_TO_UNBLOCKED, l));	
	return vec;
}
//------------------------------------------------------------
std::vector<std::unique_ptr<Enemies>> EnemyFactory::createSpiders(int level_num, Level* l, std::vector<int> v)
{
	std::vector<std::unique_ptr<Enemies>> vec;
	for (int i = 0; i < v[SMART_MONSTER]; i++)//להחזיר דחוף
		vec.emplace_back(EnemyFactory::createEnemy(sf::Vector2i(800, 500), Graphics::getGraphics().getTexture(SMART_SPIDER), SMART_MOVE, MOVE_EVERYWHERE, l));
	for (int i = 0; i < v[DOMB_MONSTER]; i++)//להחזיר דחוף
		vec.emplace_back(EnemyFactory::createEnemy(sf::Vector2i(800, 500), Graphics::getGraphics().getTexture(SPIDER), SIMPLE_MOVE, MOVE_EVERYWHERE, l));
	return vec;
}
//----------------------------------------------------------------------------------------------
std::unique_ptr<TerritoryEater> EnemyFactory::createTerritoryEater(sf::Vector2i pos, sf::Texture& t, enum MoveEnum e_move, enum WhereCanMoveEnum e_whereMove, Level* l)
{
	return std::make_unique<TerritoryEater>(t,  getMoveVec()[e_move](pos, getWhereCanMoveVec()[e_whereMove]()), l);
}
//----------------------------------------------------------------------------------------------
std::vector<std::unique_ptr<TerritoryEater>> EnemyFactory::createTerritoryEaters(int level_num, Level* l, std::vector<int> v)
{
	std::vector<std::unique_ptr<TerritoryEater>> vec;
	for (int i = 0; i < v[TERRITORY_EATER]; i++)
		vec.emplace_back(EnemyFactory::createTerritoryEater(sf::Vector2i(800, 500), Graphics::getGraphics().getTexture(TERRITORY_EATER_PIC), RANDOM_MOVE, MOVE_EVERYWHERE, l));
	return vec;
}