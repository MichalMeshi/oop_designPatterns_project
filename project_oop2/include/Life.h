#pragma once
#include "Gift.h"
class Life:public Gift
{
public:
	Life(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Gift(t,f1,f2){}
	~Life()=default;

private:

};
