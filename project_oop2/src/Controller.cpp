#include "Controller.h"
//---------------------------------
void Controller::run() 
{
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC] = std::make_unique< sf::Sound>(Graphics::getGraphics().getSound(FIRST_MUSIC));
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->play();

	StartMenu m(m_gameController);
	m.run();
}