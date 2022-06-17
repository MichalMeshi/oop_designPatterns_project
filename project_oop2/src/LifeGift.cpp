#include "LifeGift.h"
//------------------------------------------------------------
bool LifeGift::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<LifeGift>(l); });
//------------------------------------------------------------
LifeGift::LifeGift(Level* l) :Gift(Graphics::getGraphics().getTexture(HEART), GIFT_SPRITE_SHEET_SIZE, l)
{
	m_display.update(ZERO, GIFT_PIC_SIZE);
}
