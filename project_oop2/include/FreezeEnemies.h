#pragma once
#include "Gift.h"
class FreezeEnemies :public Gift
{
public:
	FreezeEnemies(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Gift(t,f1,f2)
	~FreezeEnemies()=default;

private:

};