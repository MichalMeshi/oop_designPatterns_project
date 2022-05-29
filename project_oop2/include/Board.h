#pragma once
#include <utility>
#include <memory>
#include "Gift.h"
#include "Enemies.h"
#include "Player.h"
class Board
{
public:
	Board(sf::RenderWindow& window);
	~Board() {}
	void draw(int x,int y);
	bool checkIfPassedAlready(int,int); 
	void moveEnemies();
	void handleSpaceBlockage(int x, int y, int& dx, int& dy);
	void floodFill(sf::Vector2i);
	bool checkIfMatCellEqualTo(sf::Vector2i v, enum TileState state);
	void movePlayer(int& x, int&, int&, int&);
	void setDirection(sf::Keyboard::Key key, int& dx, int& dy);

private:
	sf::RenderWindow& m_window;
	int m_matrix[45][45] = { 0 };
	sf::RectangleShape m_rec;
	std::vector<std::unique_ptr<Gift>> m_giftsVec;
	std::vector<std::unique_ptr<Enemies>> m_enemiesVec;
	Player m_player;
	Display m_backgroundGame;
};
