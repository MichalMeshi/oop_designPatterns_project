#pragma once
#include "Enemies.h"
class Board;
class Spider : public Enemies
{
public:
	Spider(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Enemies(t,f1,f2){}
	~Spider()=default;
	virtual bool move(Board& b) override { return false; }
private:
};