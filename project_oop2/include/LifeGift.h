#pragma once
#include "GiftFactory.h"
#include "Level.h"
class LifeGift:public Gift
{
public:
	LifeGift(Level* l);
	virtual ~LifeGift() override{}
	void addLife() { m_level->addLife(); }

private:
	static bool m_register;
};

