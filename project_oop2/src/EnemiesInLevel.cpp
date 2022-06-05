#include "EnemiesInLevel.h"
EnemiesInLevel::EnemiesInLevel()
{
	m_amountEnemiesInLevelMatrix.resize(2);
	m_amountEnemiesInLevelMatrix[TERRITORY_EATER].emplace_back(0);
	m_amountEnemiesInLevelMatrix[TERRITORY_EATER].emplace_back(1);
	m_amountEnemiesInLevelMatrix[TERRITORY_EATER].emplace_back(1);
	m_amountEnemiesInLevelMatrix[MONSTER].emplace_back(1);//כמה מפלצות טפשות יש בכל שלב?
	m_amountEnemiesInLevelMatrix[MONSTER].emplace_back(1);
	m_amountEnemiesInLevelMatrix[MONSTER].emplace_back(2);
}