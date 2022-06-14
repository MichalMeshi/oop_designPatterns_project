#pragma once
#include "GiftFactory.h"
#include "Level.h"
class Life:public Gift
{
public:
	Life(Level* l) :Gift(Graphics::getGraphics().getTexture(HEART), { 270,30 }, l) {
		m_display.update(0,30);
	}
	virtual ~Life() override{}
	void addLife() { m_level->addLife(); }


private:
	static bool m_register;

};

