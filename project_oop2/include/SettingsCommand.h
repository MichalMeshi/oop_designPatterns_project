#include "Command.h"
class SettingsCommand :public Command
{
public:
	SettingsCommand():Command(){}
	~SettingsCommand() = default;
	virtual void execute(sf::RenderWindow& window, Display& d)override;
};