#pragma once
#include "GiftFactory.h"
#include "Level.h"
//-----------------------------------
class AddTime :public Gift
{
public:
	AddTime(Level* l) :Gift(Graphics::getGraphics().getTexture(ADD_TIME), {270,30},l) {}
	virtual ~AddTime() override{}
	void addTime() { m_level->addTime(); }

private:
	static bool m_register;
};
