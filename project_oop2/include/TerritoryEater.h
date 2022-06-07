#pragma once
#include "Enemies.h"
class Board;
class Level;
class TerritoryEater : public Enemies
{
public:
	TerritoryEater(sf::Texture& t, sf::Vector2f f1, std::shared_ptr<Move> m, Level* l):Enemies(t,f1,m,l){}
	~TerritoryEater() {}
	virtual void move(Board& b) override;
private:
};