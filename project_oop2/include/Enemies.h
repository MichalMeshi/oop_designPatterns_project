#pragma once
#include "DynamicObj.h"
class Board;
class Enemies:public DynamicObj
{
public:
	Enemies(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):DynamicObj(t,f1,f2){}
	~Enemies()=default;
	virtual bool move(Board& b) override { return false; }
	sf::Vector2i getIndex()const { return sf::Vector2i((y - 50) / 20, (x - 350) / 20); }
	void setPosition() { Object::setPosition(x,y); }
protected:
	int x = 500, y = 500;
	int dx = 4 - rand() % 8;
	int dy = 4 - rand() % 8;
};

