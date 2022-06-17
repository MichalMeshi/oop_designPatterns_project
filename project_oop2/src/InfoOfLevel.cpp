#include "InfoOfLevel.h"
//------------------------------------------------------------
InfoOfLevel::InfoOfLevel()
{
	m_amountEnemiesInLevelMatrix.resize(4);
	m_amountEnemiesInLevelMatrix[1].emplace_back(0);//TERRITORY_EATER
	m_amountEnemiesInLevelMatrix[2].emplace_back(1);
	m_amountEnemiesInLevelMatrix[3].emplace_back(1);
	m_amountEnemiesInLevelMatrix[1].emplace_back(1);//DOMB_MONSTER
	m_amountEnemiesInLevelMatrix[2].emplace_back(1);
	m_amountEnemiesInLevelMatrix[3].emplace_back(2);
	m_amountEnemiesInLevelMatrix[1].emplace_back(0);//SMART_MONSTER
	m_amountEnemiesInLevelMatrix[2].emplace_back(0);
	m_amountEnemiesInLevelMatrix[3].emplace_back(1);
	m_amountEnemiesInLevelMatrix[1].emplace_back(75);//PERCENTAGE
	m_amountEnemiesInLevelMatrix[2].emplace_back(80);
	m_amountEnemiesInLevelMatrix[3].emplace_back(90);
	m_amountEnemiesInLevelMatrix[1].emplace_back(3);//LIFE_AMOUNT
	m_amountEnemiesInLevelMatrix[2].emplace_back(3);
	m_amountEnemiesInLevelMatrix[3].emplace_back(3);
	m_amountEnemiesInLevelMatrix[1].emplace_back(LEVEL1_BLOCKED_TILE);//INDEX_OF_BLOCKED    //from here to change
	m_amountEnemiesInLevelMatrix[2].emplace_back(LEVEL2_BLOCKED_TILE);
	m_amountEnemiesInLevelMatrix[3].emplace_back(LEVEL3_BLOCKED_TILE);
	m_amountEnemiesInLevelMatrix[1].emplace_back(LEVEL1_EMPTY_TILE);//INDEX_OF_EMPTY
	m_amountEnemiesInLevelMatrix[2].emplace_back(LEVEL2_EMPTY_TILE);
	m_amountEnemiesInLevelMatrix[3].emplace_back(LEVEL3_EMPTY_TILE);
	m_amountEnemiesInLevelMatrix[1].emplace_back(LEVEL1_MIDDLE_TILE);//INDEX_OF_MIDDLE
	m_amountEnemiesInLevelMatrix[2].emplace_back(LEVEL2_MIDDLE_TILE);
	m_amountEnemiesInLevelMatrix[3].emplace_back(LEVEL3_MIDDLE_TILE);
}