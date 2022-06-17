#include "Controller.h"
//---------------------------------
void Controller::run() 
{
	Graphics::getGraphics().createWindow();

	createSounds();
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->setVolume(VOLUME);
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->play();
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->setLoop(true);
	StartMenu m(m_gameController);
	m.run();
}
//---------------------------------
void Controller::createSounds()
{
	Graphics::getGraphics().getSoundVec()[FIRST_MUSIC] = std::make_unique< sf::Sound>(Graphics::getGraphics().getSound(FIRST_MUSIC));
	Graphics::getGraphics().getSoundVec()[CLOCK_SOUND] = std::make_unique< sf::Sound>(Graphics::getGraphics().getSound(CLOCK_SOUND));
	Graphics::getGraphics().getSoundVec()[GIFT_SOUND] = std::make_unique< sf::Sound>(Graphics::getGraphics().getSound(GIFT_SOUND));
	Graphics::getGraphics().getSoundVec()[WIN_SOUND] = std::make_unique< sf::Sound>(Graphics::getGraphics().getSound(WIN_SOUND));
	Graphics::getGraphics().getSoundVec()[CLICK_SOUND] = std::make_unique< sf::Sound>(Graphics::getGraphics().getSound(CLICK_SOUND));
	Graphics::getGraphics().getSoundVec()[FAILURE_SOUND] = std::make_unique< sf::Sound>(Graphics::getGraphics().getSound(FAILURE_SOUND));
}
