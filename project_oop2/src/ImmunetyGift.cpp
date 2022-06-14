#include "ImmunetyGift.h"
bool ImmunetyGift::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<ImmunetyGift>(l); });
