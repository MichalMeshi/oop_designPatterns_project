#include "BackSoundCommand.h"
//-------------------------------------------------------------
//פונקציה האחראית על ביצוע הפעולה של השתקת או הפעלת מוזיקת הרקע של המשחק
//-------------------------------------------------------------
void BackSoundCommand::execute(Display& d)
{
	if (Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->getVolume() == VOLUME)
	{
		d.setTexture(Graphics::getGraphics().getTexture(UN_SOUND));
		Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->setVolume(ZERO);
	}
	else
	{
		d.setTexture(Graphics::getGraphics().getTexture(SOUND));
		Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->setVolume(VOLUME);
	}
}