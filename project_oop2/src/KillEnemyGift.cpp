#include "KillEnemyGift.h"
//------------------------------------------------------------
bool KillEnemyGift::m_register = GiftFactory::registerGift([](Level* l)->std::unique_ptr<Gift> { return std::make_unique<KillEnemyGift>(l); });
//------------------------------------------------------------
KillEnemyGift::KillEnemyGift(Level* l) :Gift(Graphics::getGraphics().getTexture(GUN_ANIMATION),
	GIFT_SPRITE_SHEET_SIZE, l) 
{
	m_display.update(ZERO, GIFT_PIC_SIZE);
}
