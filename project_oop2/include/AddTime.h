#pragma once
#include "GiftFactory.h"
class AddTime :public Gift
{
public:
	AddTime(sf::Texture& t, sf::Vector2f f):Gift(t,f){}
	virtual ~AddTime() override{}

private:
	static bool m_register;
};
bool AddTime::m_register = GiftFactory::registerGift([](sf::Texture& t, sf::Vector2f f)->std::unique_ptr<Gift> { return std::make_unique<AddTime>(t, f); });
