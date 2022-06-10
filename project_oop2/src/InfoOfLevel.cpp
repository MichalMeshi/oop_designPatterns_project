#include "InfoOfLevel.h"
InfoOfLevel::InfoOfLevel()
{
	m_amountEnemiesInLevelMatrix.resize(4);
	m_amountEnemiesInLevelMatrix[1].emplace_back(0);//TERRITORY_EATER
	m_amountEnemiesInLevelMatrix[2].emplace_back(1);
	m_amountEnemiesInLevelMatrix[3].emplace_back(1);
	m_amountEnemiesInLevelMatrix[1].emplace_back(1);//DOMB_MONSTER
	m_amountEnemiesInLevelMatrix[2].emplace_back(1);
	m_amountEnemiesInLevelMatrix[3].emplace_back(2);
	m_amountEnemiesInLevelMatrix[3].emplace_back(2);
	m_amountEnemiesInLevelMatrix[1].emplace_back(0);//SMART_MONSTER
	m_amountEnemiesInLevelMatrix[2].emplace_back(0);
	m_amountEnemiesInLevelMatrix[3].emplace_back(1);
	m_amountEnemiesInLevelMatrix[1].emplace_back(70);//PERCENTAGE
	m_amountEnemiesInLevelMatrix[2].emplace_back(80);
	m_amountEnemiesInLevelMatrix[3].emplace_back(90);
	m_amountEnemiesInLevelMatrix[1].emplace_back(3);//LIFE_AMOUNT
	m_amountEnemiesInLevelMatrix[2].emplace_back(3);
	m_amountEnemiesInLevelMatrix[3].emplace_back(3);

}