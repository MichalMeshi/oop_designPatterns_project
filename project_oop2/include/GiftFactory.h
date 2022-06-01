#pragma once
#include "Gift.h"
typedef std::unique_ptr<Gift>(*giftFunc)(sf::Texture& t, sf::Vector2f);
class GiftFactory{
public:
	static bool registerGift(giftFunc mf);
	static std::unique_ptr<Gift> createGift(sf::Texture& t, sf::Vector2f);
	static std::vector<giftFunc>& getGiftVec();

private:
};