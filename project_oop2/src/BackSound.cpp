#include "BackSound.h"

void BackSound::execute(sf::RenderWindow& window, Display& d)
{
	if (Graphics::getGraphics().getSoundVec()[FIRST_MUSIC].getVolume() == 100)
	{
		d.setTexture(Graphics::getGraphics().getTexture(SEA));
		Graphics::getGraphics().getSoundVec()[FIRST_MUSIC].setVolume(0);
	}
	else
	{
		d.setTexture(Graphics::getGraphics().getTexture(INSTRUCTIONS));
		Graphics::getGraphics().getSoundVec()[FIRST_MUSIC].setVolume(100);
	}

}