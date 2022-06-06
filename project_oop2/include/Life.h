#pragma once
#include "GiftFactory.h"
class Life:public Gift
{
public:
	Life(Level* l):Gift(Graphics::getGraphics().getTexture(SEA), { 20,20 },l){	}
	virtual ~Life() override{}

private:
	static bool m_register;

};
bool Life::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<Life>(l); });

