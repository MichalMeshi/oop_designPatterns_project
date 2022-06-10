#pragma once
#include <utility>
#include <memory>
#include "EnemyFactory.h"
#include "Player.h"
#include "GiftFactory.h"
class Enemies;
class Gift;
class Board
{
public:
	Board(sf::RenderWindow& window, int, int&);
	~Board() {}
	void draw();
	bool checkIfPassedAlready();
	bool moveEnemies();
	void handleSpaceBlockage(int, int);
	void floodFill(sf::Vector2i);
	void movePlayer();
	void setDirection(sf::Keyboard::Key key);
	bool checkIfBlocked(sf::Vector2i pos) { return (m_matrix[pos.x][pos.y] == BLOCKED); }
	bool checkIUnfBlocked(sf::Vector2i pos) { return (m_matrix[pos.x][pos.y] == EMPTY || m_matrix[pos.x][pos.y] == MIDDLE); }
	void handleCreateGifts(int& gift_num, int rand_time, Level* l);
	void eatCellInMatrix(int i, int j);
	sf::Vector2f findDirectionToMove(int x, int y);
	void createEnemiesInBoard(int, Level*, std::vector<int>);
	void createTerritoryEnemiesInBoard(int, Level*, std::vector<int>);
	void handleCollision();
	bool colide(Object& obj1, Object& obj2);
	void freezeEnemies();
	void unFreeze();
	void setPlayerPositionToBegining() { m_player.setPlayerPosition(sf::Vector2f(0, 0)); }//����� ����� ����
private:
	sf::RenderWindow& m_window;
	std::vector< std::vector<int>>m_matrix;
	sf::RectangleShape m_rec;
	std::vector<std::unique_ptr<Gift>> m_giftsVec;
	std::vector<std::unique_ptr<Enemies>> m_enemiesVec;
	std::vector<std::unique_ptr<TerritoryEater>> m_territoryEaterVec;
	Player m_player;
	Display m_backgroundGame;
	//int dx = 0, dy = 0, x = 0, y = 0;
	sf::Clock clockForGifts;
	int& m_percentage;
	int m_blockCounter = 8;
	bool m_inFailure = false;


};