#include "EnemyFactory.h"
#include "TerritoryEater.h"
#include "Level.h"
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
 //----------------------------------------------------------------------------------------------

 std::unique_ptr<Enemies> EnemyFactory::createEnemy(sf::Vector2i pos,sf::Texture& t, sf::Vector2f f, enum MoveEnum e_move, enum WhereCanMoveEnum e_whereMove,Level* l)
{
	return std::make_unique<Enemies>(t, f,getMoveVec()[e_move](pos,getWhereCanMoveVec()[e_whereMove]()),l);
}
 //----------------------------------------------------------------------------------------------
 std::vector<std::unique_ptr<Enemies>> EnemyFactory::createEnemies(int level_num, Level* l,std::vector<int> v)
 {
	 int num = (rand() % 4) + level_num;
	 std::vector<std::unique_ptr<Enemies>> vec;
	 for(int i=0;i< num;i++)
		  vec.emplace_back(EnemyFactory::createEnemy(sf::Vector2i(800,500),Graphics::getGraphics().getTexture(BALL), sf::Vector2f(20, 20), SIMPLE_MOVE, MOVE_TO_UNBLOCKED,l));

	 //std::generate_n(std::back_inserter(vec), num, [] {
		// return createEnemy(sf::Vector2i(800, 500), Graphics::getGraphics().getTexture(BALL), sf::Vector2f(30, 30), SIMPLE_MOVE, MOVE_TO_UNBLOCKED,l); });
	//for(int i=0;i<v[])
//	 vec.emplace_back(EnemyFactory::createEnemy(sf::Vector2i(800,500),Graphics::getGraphics().getTexture(BACK), sf::Vector2f(20, 20), SMART_MOVE, MOVE_TO_UNBLOCKED));
	vec.emplace_back(EnemyFactory::createEnemy(sf::Vector2i(1200, 70), Graphics::getGraphics().getTexture(SPIDER), sf::Vector2f(30, 30),SMART_MOVE, MOVE_EVERYWHERE,l));
	//����� �� ���� ������� �� ������ ���
//vec.emplace_back(std::make_unique<TerritoryEater>(Graphics::getGraphics().getTexture(SPIDER), sf::Vector2f(30, 30), getMoveVec()[RANDOM_MOVE](sf::Vector2i(800, 500), getWhereCanMoveVec()[MOVE_EVERYWHERE]()),l));

	return vec;
 }