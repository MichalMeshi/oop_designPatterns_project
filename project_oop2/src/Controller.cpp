#include "Controller.h"
//---------------------------------
void Controller::run() 
{
	sf::Sound music(Graphics::getGraphics().getSound(FIRST_MUSIC));
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]= music;
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC].play(); 

	StartMenu m(m_gameController);
	m.run();
}