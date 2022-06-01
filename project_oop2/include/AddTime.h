#pragma once
#include "GiftFactory.h"
class AddTime :public Gift
{
public:
	AddTime() :Gift(Graphics::getGraphics().getTexture(INSTRUCTIONS), {20,20}) {}
	virtual ~AddTime() override{}

private:
	static bool m_register;
};
bool AddTime::m_register = GiftFactory::registerGift([]()->std::unique_ptr<Gift> { return std::make_unique<AddTime>(); });
