#include "Noise.h"

void Noise::execute(sf::RenderWindow& window)
{
	for (int i = 1; i < Graphics::getGraphics().getSoundVec().size(); i++)
		Graphics::getGraphics().getSoundVec()[i].setVolume(0);
}
void Noise::unExecute(sf::RenderWindow& window)
{
	for (int i = 1; i < Graphics::getGraphics().getSoundVec().size(); i++)
		Graphics::getGraphics().getSoundVec()[i].setVolume(100);

}
