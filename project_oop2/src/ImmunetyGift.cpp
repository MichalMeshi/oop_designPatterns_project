#include "ImmunetyGift.h"
bool ImmunetyGift::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<ImmunetyGift>(l); });

ImmunetyGift::ImmunetyGift(Level* l)
	:Gift(Graphics::getGraphics().getTexture(IMMUNE_ANIMATION), GIFT_SPRITE_SHEET_SIZE, l)
{
	m_display.update(ZERO, GIFT_PIC_SIZE);
}
