#pragma once
#include "Gift.h"
typedef std::unique_ptr<Gift>(*giftFunc)();
class GiftFactory{
public:
	static bool registerGift(giftFunc mf);
	static std::unique_ptr<Gift> createGift();
	static std::vector<giftFunc>& getGiftVec();

private:
};