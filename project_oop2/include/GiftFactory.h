#pragma once
#include "Gift.h"
typedef std::unique_ptr<Gift>(*giftFunc)(Level* l);
class GiftFactory{
public:
	static bool registerGift(giftFunc mf);
	static std::unique_ptr<Gift> createGift(Level*);
	static std::vector<giftFunc>& getGiftVec();
private:
};