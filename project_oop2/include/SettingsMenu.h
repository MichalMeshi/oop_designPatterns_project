#pragma once
#include "Menu.h"
#include "ShowInstructions.h"
#include "Scores.h"
#include "Noise.h"
#include "BackSound.h"
class SettingsMenu:public Menu
{
public:
	SettingsMenu(sf::RenderWindow& w);
	~SettingsMenu()=default;
 virtual void handleBoard() override;

private:
	Display m_back;
};
