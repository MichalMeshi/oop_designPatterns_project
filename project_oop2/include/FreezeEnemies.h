#pragma once
#include "GiftFactory.h"

class FreezeEnemies :public Gift
{
public:
	FreezeEnemies(Level* l) :Gift(Graphics::getGraphics().getTexture(SEA), { 20,20 },l) {	}
	virtual	~FreezeEnemies()override {}

private:
	static bool m_register;
};

bool FreezeEnemies::m_register = GiftFactory::registerGift(
	[](Level* l)->std::unique_ptr<Gift> { return std::make_unique<FreezeEnemies>(l); });
