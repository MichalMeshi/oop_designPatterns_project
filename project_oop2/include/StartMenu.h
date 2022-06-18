#pragma once
#include "NewGameCommand.h"
#include "Menu.h"
//-----------------------------------------------
class StartMenu:public Menu{
public:
	StartMenu(GameController& );
	virtual ~StartMenu() {}
	virtual void run()override;
private:
};
