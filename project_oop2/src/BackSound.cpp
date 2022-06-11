#include "BackSound.h"

void BackSound::execute(sf::RenderWindow& window)
{
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC].setVolume(0);
}
void BackSound::unExecute(sf::RenderWindow& window)
{
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC].setVolume(100);
}
