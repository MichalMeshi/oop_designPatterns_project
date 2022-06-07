#include "AddTime.h"
bool AddTime::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<AddTime>(l); });
