#include "EnemiesInLevel.h"
EnemiesInLevel::EnemiesInLevel()
{
	m_amountEnemiesInLevelMatrix.resize(3);
	m_amountEnemiesInLevelMatrix[TERRITORY_EATER].emplace_back(0);
	m_amountEnemiesInLevelMatrix[TERRITORY_EATER].emplace_back(1);
	m_amountEnemiesInLevelMatrix[TERRITORY_EATER].emplace_back(1);
	m_amountEnemiesInLevelMatrix[DOMB_MONSTER].emplace_back(1);
	m_amountEnemiesInLevelMatrix[DOMB_MONSTER].emplace_back(1);
	m_amountEnemiesInLevelMatrix[DOMB_MONSTER].emplace_back(2);
	m_amountEnemiesInLevelMatrix[SMART_MONSTER].emplace_back(0);
	m_amountEnemiesInLevelMatrix[SMART_MONSTER].emplace_back(0);
	m_amountEnemiesInLevelMatrix[SMART_MONSTER].emplace_back(1);
}