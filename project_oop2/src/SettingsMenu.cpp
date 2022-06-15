#include "SettingsMenu.h"
SettingsMenu::SettingsMenu()
	: Menu(sf::VideoMode(WIDTH_WINDOW, HIGTH_WINDOW), "SETTINGS", Display(Graphics::getGraphics().getTexture(SETTING_VIEW), BEGGINING_WINDOW, sf::Vector2f(WIDTH_WINDOW, HIGTH_WINDOW)))
{
	addCellToVec(std::make_pair(std::move(std::make_unique<ShowInstructionsCommand>()), Display(Graphics::getGraphics().getTexture(HELP), HELP_POSITION, COMMAND_PIC_SIZE)));
	if (Graphics::getGraphics().getSoundVec()[FIRST_MUSIC]->getVolume() == VOLUME)
		addCellToVec(std::make_pair(std::move(std::make_unique<BackSoundCommand>()), Display(Graphics::getGraphics().getTexture(SOUND), SOUND_POSITION, COMMAND_PIC_SIZE)));
	else
		addCellToVec(std::make_pair(std::move(std::make_unique<BackSoundCommand>()), Display(Graphics::getGraphics().getTexture(UN_SOUND), SOUND_POSITION, COMMAND_PIC_SIZE)));
	if (Graphics::getGraphics().getSoundVec()[CLICK_SOUND]->getVolume() == VOLUME)
		addCellToVec(std::make_pair(std::move(std::make_unique<NoiseCommand>()), Display(Graphics::getGraphics().getTexture(NOISE), NOISE_POSITION, COMMAND_PIC_SIZE)));
	else
		addCellToVec(std::make_pair(std::move(std::make_unique<NoiseCommand>()), Display(Graphics::getGraphics().getTexture(UN_NOISE), NOISE_POSITION, COMMAND_PIC_SIZE)));
	m_menu[HELP].second.setOrigin(HALF_COMMAND_PIC_LENGTH, HALF_COMMAND_PIC_LENGTH);
	m_menu[SOUND].second.setOrigin(HALF_COMMAND_PIC_LENGTH, HALF_COMMAND_PIC_LENGTH);
	m_menu[NOISE].second.setOrigin(HALF_COMMAND_PIC_LENGTH, HALF_COMMAND_PIC_LENGTH);
}
