#pragma once
#include "Object.h"
class StaticObj : public Object
{
public:
	StaticObj(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2) :Object(t,f1,f2) {}
	virtual ~StaticObj()=0{}

private:
	

};