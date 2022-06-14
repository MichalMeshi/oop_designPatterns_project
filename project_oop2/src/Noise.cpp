#include "Noise.h"

void Noise::execute(sf::RenderWindow& window, Display& d)
{
	if (d.getTexture() == &Graphics::getGraphics().getTexture(NOISE))
	{
		d.setTexture(Graphics::getGraphics().getTexture(UN_NOISE));
		for (int i = 1; i < Graphics::getGraphics().getSoundVec().size(); i++)
			if(Graphics::getGraphics().getSoundVec()[i]!=nullptr)
				Graphics::getGraphics().getSoundVec()[i]->setVolume(0);
	}
	else
	{
		d.setTexture(Graphics::getGraphics().getTexture(NOISE));
		for (int i = 1; i < Graphics::getGraphics().getSoundVec().size(); i++)
			if (Graphics::getGraphics().getSoundVec()[i] != nullptr)
				Graphics::getGraphics().getSoundVec()[i]->setVolume(100);
	}	
}
