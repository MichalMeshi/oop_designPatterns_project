#pragma once
#include "GiftFactory.h"
#include "Level.h"

class FreezeEnemies :public Gift
{
public:
	FreezeEnemies(Level* l) :Gift(Graphics::getGraphics().getTexture(FREEZE_ENEMIES), { 270,30 },l) {	}
	virtual	~FreezeEnemies()override {}
	void freezeEnemies() { m_level->freezeEnemies(); }

private:
	static bool m_register;
};

