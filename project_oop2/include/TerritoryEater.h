#pragma once
#include "Enemies.h"
class Board;
class Level;
//-----------------------------------------------
class TerritoryEater : public Enemies{
public:
	TerritoryEater(sf::Texture& t, std::shared_ptr<Move> m, Level* l) :Enemies(t,  m, l) {}
	virtual ~TerritoryEater() {}
	void move(Board& b) override;
};