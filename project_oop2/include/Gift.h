#pragma once
#include "StaticObj.h"
class Gift: public StaticObj
{
public:
	 Gift(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):StaticObj(t,f1,f2){}
	 virtual ~Gift() = 0 {}
protected:

};