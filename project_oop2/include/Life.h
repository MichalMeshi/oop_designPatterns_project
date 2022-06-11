#pragma once
#include "GiftFactory.h"
#include "Level.h"
class Life:public Gift
{
public:
	Life(Level* l):Gift(Graphics::getGraphics().getTexture(HEART), { 20,20 },l){	}
	virtual ~Life() override{}
	void addLife() { m_level->addLife(); }

private:
	static bool m_register;

};

