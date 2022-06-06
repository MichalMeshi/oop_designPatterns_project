#pragma once
#include "Enemies.h"
class Board;
class TerritoryEater : public Enemies
{
public:
	TerritoryEater(sf::Texture& t, sf::Vector2f f1, std::unique_ptr<Move> m):Enemies(t,f1,std::move(m)){}
	~TerritoryEater() {}
	virtual void move(Board& b) override;
private:
};