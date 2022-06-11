#pragma once
#include "GiftFactory.h"
#include "Level.h"
class AddTime :public Gift
{
public:
	AddTime(Level* l) :Gift(Graphics::getGraphics().getTexture(CLOCKPICTURE), {20,20},l) {}
	virtual ~AddTime() override{}
	void addTime() { m_level->addTime(); }

private:
	static bool m_register;
};
