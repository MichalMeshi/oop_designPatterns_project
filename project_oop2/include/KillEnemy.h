#pragma once
#include "GiftFactory.h"
#include "Level.h"
class KillEnemy :public Gift
{
public:
	KillEnemy(Level* l) :Gift(Graphics::getGraphics().getTexture(GUN_ANIMATION), { 270,30 }, l) {
		m_display.update(0, 30);
	}
	virtual ~KillEnemy() override {}
	void kill() { m_level->restartClockForGift(); }


private:
	static bool m_register;

};
