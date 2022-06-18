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
//-----------------------------------
class Board {
public:
	Board(int, int&);
	~Board() {}
	void draw(std::vector<int>);
	bool checkIfPassedAlready();
	bool moveEnemies();
	void handleSpaceBlockage();
	void movePlayer();
	void setDirection(sf::Keyboard::Key key);
	bool checkIfBlocked(sf::Vector2i pos) const;
	bool checkIUnfBlocked(sf::Vector2i pos)const;
	void handleCreateGifts(int& gift_num, int rand_time, Level* l);
	void eatCellInMatrix(int i, int j);
	sf::Vector2f findDirectionToMove(int x, int y);
	void createEnemiesInBoard(int, Level*, std::vector<int>);
	void createTerritoryEnemiesInBoard(int, Level*, std::vector<int>);
	void handleCollision();
	void freezeEnemies();
	void unFreezeEnemies();
	void rotateGifts();
	void updateFailure(bool b) { m_inFailure = b; }
	void handleAnimationCrumb(int i, int j);
	void setPlayerPositionToBegining();
	void immuneThePlayer();
	void changePlayerToKilling();
	void setPlayer();
private:
	std::vector< std::vector<int>>m_matrix;
	std::vector<std::unique_ptr<Gift>> m_giftsVec;
	std::vector<std::unique_ptr<Enemies>> m_ballsVec;
	std::vector<std::unique_ptr<Enemies>> m_spidersVec;
	std::vector<std::unique_ptr<TerritoryEater>> m_territoryEaterVec;
	std::unique_ptr<Player> m_player;
	Display m_backgroundGame;
	Display m_crumbPic;
	sf::Clock clockForGifts;
	int& m_percentage;
	int m_blockCounter = ZERO;
	bool m_inFailure = false;
	Animation m_crumbAnimation;
	
	void createBoard();
	void setBackPlayer(); 
	void drawTiles(std::vector<int> infoVec)const;
	void drawObjects();
	void handleConditionTile();
	void eraseDeletedObjects();
	void floodFill();
	void floodFill(sf::Vector2i);
	template<typename enemyVec>
	void floodFillOnEnemy(std::vector<typename enemyVec>& vec);
	template <typename enemyVec>
	void unFreezeEnemies(std::vector<typename enemyVec>& vec);
	template <typename enemyVec>
	void freezeEnemies(std::vector<typename enemyVec>& vec);
	void handleEnemiesCollision(std::vector<std::unique_ptr<Enemies>>& vec, Player& );
	bool colide(Object& obj1, Object& obj2)const;
	template <typename enemyVec>
	void drawVec(std::vector<typename enemyVec>&);
	template <typename enemyVec>
	void moveEnemiesVec(std::vector<typename enemyVec>& enemiesVec, bool&);
};