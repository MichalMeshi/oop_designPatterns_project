#pragma once
#include "Gift.h"
typedef std::unique_ptr<Gift>(*giftFunc)(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2);
class GiftFactory{
public:
	static bool registerGift(giftFunc mf);
	static std::unique_ptr<Gift> createGift(sf::Texture& t, sf::Vector2f f1, sf::Vector2f f2);
	static std::vector<giftFunc>& getGiftVec();
private:
};