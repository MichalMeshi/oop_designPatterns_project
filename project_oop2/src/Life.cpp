#include "Life.h"
bool Life::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<Life>(l); });
