#pragma once
#include "GiftFactory.h"
class AddTime :public Gift
{
public:
	AddTime(Level* l) :Gift(Graphics::getGraphics().getTexture(INSTRUCTIONS), {20,20},l) {}
	virtual ~AddTime() override{}

private:
	static bool m_register;
};
bool AddTime::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<AddTime>(l); });
