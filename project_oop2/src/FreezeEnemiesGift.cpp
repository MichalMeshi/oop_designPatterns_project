#include "FreezeEnemiesGift.h"
//------------------------------------------------------------
bool FreezeEnemiesGift::m_register = GiftFactory::registerGift(
	[](Level* l)->std::unique_ptr<Gift> { return std::make_unique<FreezeEnemiesGift>(l); });