#pragma once
#include "GameController.h"
#include "StartMenu.h"
//------------------------------------------
class Controller {
public:
	Controller():m_gameController() {}
	~Controller(){}
	void run();
private:
	GameController m_gameController;
	void createSounds();
	void playBackSound();

};