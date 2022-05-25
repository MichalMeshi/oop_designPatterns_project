#pragma once
#include "DynamicObj.h"
class Board;
class Player :public DynamicObj
{
public:
	Player(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):DynamicObj(t,f1,f2){}
	~Player() = default;
	virtual bool move(Board& b) override { return false; }
private:

};