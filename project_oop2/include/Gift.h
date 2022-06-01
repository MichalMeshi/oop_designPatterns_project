#pragma once
#include "StaticObj.h"
class Gift: public StaticObj
{
public:
	 Gift(sf::Texture& t, sf::Vector2f f):StaticObj(t,f) {}
	 virtual ~Gift() = 0 {}
protected:

};