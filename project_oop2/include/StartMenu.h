#pragma once
#include "NewGameCommand.h"
#include "Menu.h"
//-----------------------------------------------
class StartMenu:public Menu{
public:
	StartMenu(GameController& );
	~StartMenu() = default;
	virtual void run()override;
private:
};
