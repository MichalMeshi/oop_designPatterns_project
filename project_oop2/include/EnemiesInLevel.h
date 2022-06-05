#pragma once
#include <vector>
struct EnemiesInLevel {
	EnemiesInLevel();
	std::vector <std::vector<int>> m_amountEnemiesInLevelMatrix;
};
EnemiesInLevel::EnemiesInLevel()
{
	m_amountEnemiesInLevelMatrix.resize(45);
}