#pragma once
#include "GiftFactory.h"

class FreezeEnemies :public Gift
{
public:
	FreezeEnemies(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Gift(t,f1,f2){}
	virtual	~FreezeEnemies()override {}

private:
	static bool m_register;
};

bool FreezeEnemies::m_register = GiftFactory::registerGift(
	[](sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2)->std::unique_ptr<Gift> { return std::make_unique<FreezeEnemies>(t, f1, f2); });
