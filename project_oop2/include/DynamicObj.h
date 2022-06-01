#pragma once
#include "Animation.h"
#include "Object.h"
class Board;
class DynamicObj :public Object
{
public:
	DynamicObj(sf::Texture& t, sf::Vector2f f):Object(t,f){}
	~DynamicObj() {}
	virtual void move(Board& b) = 0;
protected:
	//Animation m_animation;

};