#include "SettingsMenu.h"
//פונקציה האחראית על ביצוע תפריט של הגדרות
void SettingsCommand::execute(Display& d)
{
	SettingsMenu().run();
}