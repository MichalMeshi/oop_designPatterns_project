#pragma once
#include "GiftFactory.h"
#include "Level.h"
//-----------------------------------
class AddTimeGift :public Gift
{
public:
	AddTimeGift(Level* l); 
	virtual ~AddTimeGift() override{}
	void addTime() { m_level->addTime(); }

private:
	static bool m_register;
};
