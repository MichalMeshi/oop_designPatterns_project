#pragma once
#include "GiftFactory.h"
class Life:public Gift
{
public:
	Life(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Gift(t,f1,f2){}
	virtual ~Life() override{}

private:
	static bool m_register;

};
bool Life::m_register = GiftFactory::registerGift([](sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2)->std::unique_ptr<Gift> { return std::make_unique<Life>(t,f1,f2); });

