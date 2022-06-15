#include "LifeGift.h"

LifeGift::LifeGift(Level* l) :Gift(Graphics::getGraphics().getTexture(HEART), { 270,30 }, l) {
	m_display.update(ZERO, GIFT_PIC_SIZE);
}
bool LifeGift::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<LifeGift>(l); });
