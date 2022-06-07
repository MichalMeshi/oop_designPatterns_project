#include "FreezeEnemies.h"

bool FreezeEnemies::m_register = GiftFactory::registerGift(
	[](Level* l)->std::unique_ptr<Gift> { return std::make_unique<FreezeEnemies>(l); });