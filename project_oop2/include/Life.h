#pragma once
#include "GiftFactory.h"
class Life:public Gift
{
public:
	Life(sf::Texture& t, sf::Vector2f f):Gift(t,f){	}
	virtual ~Life() override{}

private:
	static bool m_register;

};
bool Life::m_register = GiftFactory::registerGift([](sf::Texture& t, sf::Vector2f f)->std::unique_ptr<Gift> { return std::make_unique<Life>(t,f); });

