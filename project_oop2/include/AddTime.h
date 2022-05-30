#pragma once
#include "GiftFactory.h"
class AddTime :public Gift
{
public:
	AddTime(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2):Gift(t,f1,f2){}
	virtual ~AddTime() override{}

private:
	static bool m_register;
};
bool AddTime::m_register = GiftFactory::registerGift([](sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2)->std::unique_ptr<Gift> { return std::make_unique<AddTime>(t, f1, f2); });
