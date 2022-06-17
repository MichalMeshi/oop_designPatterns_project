#pragma once
#include "GiftFactory.h"
#include "Level.h"
//---------------------------------------
class ImmunetyGift :public Gift{
public:
	ImmunetyGift(Level* l);
	virtual ~ImmunetyGift() override {}
	void immune() { m_level->immuneThePlayer();  m_level->restartClockForGift();}
private:
	static bool m_register;
};
