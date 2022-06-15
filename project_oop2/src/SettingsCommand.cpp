#include "SettingsMenu.h"
//פונקציה האחראית על ביצוע תפריט של הגדרות
void SettingsCommand::execute(sf::RenderWindow& window, Display& d)
{
	SettingsMenu().run();
}