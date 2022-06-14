#pragma once
#include "GiftFactory.h"
#include "Level.h"
class ImmunetyGift :public Gift
{
public:
	ImmunetyGift(Level* l) :Gift(Graphics::getGraphics().getTexture(GUN_ANIMATION), { 270,30 }, l) {
		m_display.update(0, 30);
	}
	virtual ~ImmunetyGift() override {}
	void immune() { m_level->immuneThePlayer();  m_level->restartClockForGift();}


private:
	static bool m_register;

};
