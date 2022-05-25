#pragma once
#include "Enemies.h"
class Board;
class Ball: public Enemies
{
public:
	Ball(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Enemies(t,f1,f2){}
	~Ball() = default;
	virtual bool move(Board& b) override;
private:
};