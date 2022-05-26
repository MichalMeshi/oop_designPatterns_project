#pragma once
#include "Animation.h"
#include "Object.h"
class Board;
class DynamicObj :public Object
{
public:
	DynamicObj(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Object(t,f1,f2){}
	~DynamicObj() {}
	virtual bool move(Board& b) = 0;
protected:
	//Animation m_animation;

};