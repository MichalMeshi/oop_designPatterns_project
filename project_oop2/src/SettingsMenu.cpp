#include "SettingsMenu.h"
//------------------------------------------------------------
SettingsMenu::SettingsMenu()
	: Menu(Display(Graphics::getGraphics().getTexture(SETTING_VIEW), BEGGINING_WINDOW, sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW))),
	m_back(Graphics::getGraphics().getTexture(BACK), BEGGINING_WINDOW, BACK_BOTTON_SIZE)
{
	initializeButtons();
	m_menu[HELP].second.setOrigin(HALF_COMMAND_PIC_LENGTH, HALF_COMMAND_PIC_LENGTH);
	m_menu[SOUND].second.setOrigin(HALF_COMMAND_PIC_LENGTH, HALF_COMMAND_PIC_LENGTH);
	m_menu[NOISE].second.setOrigin(HALF_COMMAND_PIC_LENGTH, HALF_COMMAND_PIC_LENGTH);
}
//-----------------------------------------
void SettingsMenu::initializeButtons()
{
	addCellToVec(std::make_pair(std::move(std::make_unique<ShowInstructionsCommand>()), Display(Graphics::getGraphics().getTexture(HELP), HELP_POSITION, COMMAND_PIC_SIZE)));
	if (Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->getVolume() == VOLUME)
		addCellToVec(std::make_pair(std::move(std::make_unique<BackSoundCommand>()), Display(Graphics::getGraphics().getTexture(SOUND), SOUND_POSITION, COMMAND_PIC_SIZE)));
	else
		addCellToVec(std::make_pair(std::move(std::make_unique<BackSoundCommand>()), Display(Graphics::getGraphics().getTexture(UN_SOUND), SOUND_POSITION, COMMAND_PIC_SIZE)));
	if (Graphics::getGraphics().getSoundVec()[CLICK_SOUND]->getVolume() == NOISE_VOLUME)
		addCellToVec(std::make_pair(std::move(std::make_unique<NoiseCommand>()), Display(Graphics::getGraphics().getTexture(NOISE), NOISE_POSITION, COMMAND_PIC_SIZE)));
	else
		addCellToVec(std::make_pair(std::move(std::make_unique<NoiseCommand>()), Display(Graphics::getGraphics().getTexture(UN_NOISE), NOISE_POSITION, COMMAND_PIC_SIZE)));
}
//פונקציה האחראית על הריצה של התפריט המשני
//-----------------------------------------
void SettingsMenu::run()
{
	while (Graphics::getGraphics().getWindow().isOpen())
	{
		Graphics::getGraphics().getWindow().clear();
		handleBoard();
		m_back.draw();
		Graphics::getGraphics().getWindow().display();
		if (auto event = sf::Event{}; Graphics::getGraphics().getWindow().waitEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed: {
				Graphics::getGraphics().getWindow().close();
				return;
			}
			case sf::Event::MouseButtonReleased: {
				handlePress(Graphics::getGraphics().getWindow().mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
			}
			case sf::Event::MouseMoved: {
				if (m_back.getSprite().getGlobalBounds().contains(Graphics::getGraphics().getWindow().mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					return;
				handleMouseMove(Graphics::getGraphics().getWindow().mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }));
				break;
			}
			}
		}
	}
}
