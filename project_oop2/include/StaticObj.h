#pragma once
#include "Object.h"
//-----------------------------------------------
class StaticObj : public Object{
public:
	StaticObj(sf::Texture& t, sf::Vector2f f) :Object(t,f) {}
	virtual ~StaticObj()=0{}
private:
};