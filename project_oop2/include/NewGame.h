#pragma once
#include "Command.h"
#include "GameController.h"
class NewGame:public Command
{
public:
	NewGame(GameController& game) :m_game(game), Command() {}
	~NewGame() = default;

	virtual void execute()override { m_game.runTheGame(); }
private:
	GameController& m_game;
};
