#pragma once
#include "Enemies.h"
class Ball: public Enemies
{
public:
	Ball() = default;
	Ball(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Enemies(t,f1,f2){}
	~Ball() { }
	virtual bool move(Board& b) override;
private:
};