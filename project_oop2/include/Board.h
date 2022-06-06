#pragma once
#include <utility>
#include <memory>
#include "EnemyFactory.h"
#include "Player.h"
#include "EnemiesInLevel.h"

#include "GiftFactory.h"
class Enemies;
class Board
{
public:
	Board(sf::RenderWindow& window,int);
	~Board() {}
	void draw();
	bool checkIfPassedAlready(); 
	void moveEnemies();
	void handleSpaceBlockage();
	void floodFill(sf::Vector2i);
	void movePlayer();
	void setDirection(sf::Keyboard::Key key);
	//void creatSimpleEnemies(int num);
	//void createGifts(int num);
	bool checkIfBlocked(sf::Vector2i pos) { return (m_matrix[pos.x][pos.y] == BLOCKED); }
	bool checkIUnfBlocked(sf::Vector2i pos) { return (m_matrix[pos.x][pos.y] == EMPTY); }
	void handleCreateGifts(int& gift_num, int rand_time);
	void eatCellInMatrix(int i, int j);
	sf::Vector2f findDirectionToMove(int x, int y);
private:
	sf::RenderWindow& m_window;
	std::vector< std::vector<int>>m_matrix;
	//int m_matrix[45][45] = { 0 };
	sf::RectangleShape m_rec;
	std::vector<std::unique_ptr<Gift>> m_giftsVec;
	std::vector<std::unique_ptr<Enemies>> m_enemiesVec;
	Player m_player;
	Display m_backgroundGame;
	//int dx = 0, dy = 0, x = 0, y = 0;
	sf::Clock clockForGifts;
	int m_percentage=0;
	int m_blockCounter=0;

};
