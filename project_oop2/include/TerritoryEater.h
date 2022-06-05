#pragma once
#include "Enemies.h"
class Board;
class TerritoryEater : public Enemies
{
public:
	TerritoryEater(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Enemies(t,f1,f2){}
	~TerritoryEater() {}
	virtual bool move(Board& b) override { return false; }
private:
};