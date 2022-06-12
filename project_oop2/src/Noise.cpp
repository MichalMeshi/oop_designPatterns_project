#include "Noise.h"

void Noise::execute(sf::RenderWindow& window, Display& d)
{
	for (int i = 1; i < Graphics::getGraphics().getSoundVec().size(); i++)
	{
		if (Graphics::getGraphics().getSoundVec()[i].getVolume() == 100)
		{
			d.setTexture(Graphics::getGraphics().getTexture(UN_NOISE));
			Graphics::getGraphics().getSoundVec()[i].setVolume(0);
		}
		else
		{
			d.setTexture(Graphics::getGraphics().getTexture(NOISE));
			Graphics::getGraphics().getSoundVec()[i].setVolume(100);
		}
	}
}
