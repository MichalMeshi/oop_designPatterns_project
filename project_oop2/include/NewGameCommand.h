#pragma once
#include "Command.h"
#include "GameController.h"
//-----------------------------------------------
class NewGameCommand:public Command{
public:
	NewGameCommand(GameController& game) :m_game(game), Command() {}
	~NewGameCommand() = default;
	virtual void execute(Display& d)override { m_game.runTheGame(); }
private:
	GameController& m_game;
};
