#pragma once
#include "NewGame.h"
#include "Menu.h"

class StartMenu:public Menu
{
public:
	StartMenu(GameController& ,sf::RenderWindow&);
	~StartMenu() {}
private:
};


//בתפריט הראשוני יש וקטור של שניים- סטינגס ומשחק חדש.
//בתפריט השני יש וקטור של כל השאר. 
//של מוזיקה - שתיים
//של טבלת שיאים ושל הוראות