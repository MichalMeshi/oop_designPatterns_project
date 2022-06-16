#pragma once
#include "Menu.h"
#include "ShowInstructionsCommand.h"
#include "NoiseCommand.h"
#include "BackSoundCommand.h"
class SettingsMenu:public Menu
{
public:
	SettingsMenu();
	~SettingsMenu()=default;
	virtual void run()override;
private:
	Display m_back;
};
