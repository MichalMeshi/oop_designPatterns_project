#include "Command.h"
class Settings :public Command
{
public:
	Settings():Command(){}
	~Settings() = default;
	virtual void execute()override;
private:
};