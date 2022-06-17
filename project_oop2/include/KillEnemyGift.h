#pragma once
#include "GiftFactory.h"
#include "Level.h"
//-----------------------------------------------
class KillEnemyGift :public Gift{
public:
	KillEnemyGift(Level* l);
	virtual ~KillEnemyGift() override {}
	void kill() { m_level->restartClockForGift(); m_level->changePlayerToKilling(); }
private:
	static bool m_register;
};
