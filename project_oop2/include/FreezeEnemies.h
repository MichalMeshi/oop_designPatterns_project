#pragma once
#include "GiftFactory.h"

class FreezeEnemies :public Gift
{
public:
	FreezeEnemies() :Gift(Graphics::getGraphics().getTexture(SEA), { 20,20 }) {	}
	virtual	~FreezeEnemies()override {}

private:
	static bool m_register;
};

bool FreezeEnemies::m_register = GiftFactory::registerGift(
	[]()->std::unique_ptr<Gift> { return std::make_unique<FreezeEnemies>(); });
