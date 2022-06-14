#include "KillEnemy.h"
bool KillEnemy::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<KillEnemy>(l); });
