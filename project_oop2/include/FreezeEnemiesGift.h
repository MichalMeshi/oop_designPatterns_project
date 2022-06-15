#pragma once
#include "GiftFactory.h"
#include "Level.h"

class FreezeEnemiesGift :public Gift
{
public:
	FreezeEnemiesGift(Level* l) :Gift(Graphics::getGraphics().getTexture(FREEZE_ENEMIES), { 270,30 },l) {	}
	virtual	~FreezeEnemiesGift()override {}
	void freezeEnemies() { m_level->freezeEnemies(); }

private:
	static bool m_register;
};

