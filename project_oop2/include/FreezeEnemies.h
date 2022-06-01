#pragma once
#include "GiftFactory.h"

class FreezeEnemies :public Gift
{
public:
	FreezeEnemies(sf::Texture& t, sf::Vector2f f):Gift(t,f){}
	virtual	~FreezeEnemies()override {}

private:
	static bool m_register;
};

bool FreezeEnemies::m_register = GiftFactory::registerGift(
	[](sf::Texture& t, sf::Vector2f f)->std::unique_ptr<Gift> { return std::make_unique<FreezeEnemies>(t, f); });
