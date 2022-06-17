#include "AddTimeGift.h"
//-----------------------------------------------
bool AddTimeGift::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<AddTimeGift>(l); });
//-----------------------------------------------
//פונקציה שמוסיפה זמן
AddTimeGift::AddTimeGift(Level* l)
	:Gift(Graphics::getGraphics().getTexture(ADD_TIME), GIFT_SPRITE_SHEET_SIZE, l) {}

