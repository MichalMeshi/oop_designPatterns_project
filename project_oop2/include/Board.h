#pragma once
#include <utility>
#include <memory>
#include "EnemyFactory.h"
#include "Player.h"
#include "GiftFactory.h"
#include "ImmunePlayer.h"
#include "KillingPlayer.h"
#include <algorithm>
class Enemies;
class Gift;
class Board
{
public:
	Board(sf::RenderWindow& window, int, int&);
	~Board() {}
	void draw(std::vector<int>);
	bool checkIfPassedAlready();
	bool moveEnemies();
	void handleSpaceBlockage();
	void floodFill(sf::Vector2i);
	void movePlayer();
	void setDirection(sf::Keyboard::Key key);
	bool checkIfBlocked(sf::Vector2i pos) const{ return (m_matrix[pos.x][pos.y] == BLOCKED); }
	bool checkIUnfBlocked(sf::Vector2i pos)const { return (m_matrix[pos.x][pos.y] == EMPTY || m_matrix[pos.x][pos.y] == MIDDLE); }
	void handleCreateGifts(int& gift_num, int rand_time, Level* l);
	void eatCellInMatrix(int i, int j);
	sf::Vector2f findDirectionToMove(int x, int y);
	void createEnemiesInBoard(int, Level*, std::vector<int>);
	void createTerritoryEnemiesInBoard(int, Level*, std::vector<int>);
	void handleCollision();
	bool colide(Object& obj1, Object& obj2)const;
	void freezeEnemies();
	void unFreezeEnemies();
	void rotateGifts();
	void updateFailure(bool b) { m_inFailure = b; }
	void handleAnimationCrumb(int i, int j);
	void setPlayerPositionToBegining() { m_player->setPlayerPosition(sf::Vector2f(22, 0)); }//לשנות למרכז למטה
	void immuneThePlayer() {
		//m_player = nullptr;
		m_player = std::make_unique < ImmunePlayer>(m_player->getPlayerXpos(), m_player->getPlayerYpos(), m_player->getPlayerDx(), m_player->getPlayerDy());
	}
	void changePlayerToKilling(){
		//m_player = nullptr;
		m_player = std::make_unique < KillingPlayer>(m_player->getPlayerXpos(), m_player->getPlayerYpos(), m_player->getPlayerDx(), m_player->getPlayerDy());
	}
	void setPlayer();
private:
	sf::RenderWindow& m_window;
	std::vector< std::vector<int>>m_matrix;
	sf::RectangleShape m_rec;
	std::vector<std::unique_ptr<Gift>> m_giftsVec;
	std::vector<std::unique_ptr<Enemies>> m_ballsVec;
	std::vector<std::unique_ptr<Enemies>> m_spidersVec;
	std::vector<std::unique_ptr<TerritoryEater>> m_territoryEaterVec;
	std::unique_ptr<Player> m_player;
	Display m_backgroundGame;
	Display m_crumbPic;
	//int dx = 0, dy = 0, x = 0, y = 0;
	sf::Clock clockForGifts;
	int& m_percentage;
	int m_blockCounter = 0;
	bool m_inFailure = false;
	//sf::Vector2f posAnimation = { 0,0 };
	Animation m_crumbAnimation;

	void setBackPlayer() { 
		//m_player = nullptr;
		m_player = std::make_unique<Player>(m_player->getPlayerXpos(), m_player->getPlayerYpos(),m_player->getPlayerDx(), m_player->getPlayerDy());
	}//פונקציה פרטית

};