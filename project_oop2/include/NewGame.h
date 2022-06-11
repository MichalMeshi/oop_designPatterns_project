#pragma once
#include "Command.h"
#include "GameController.h"
class NewGame:public Command
{
public:
	NewGame(GameController& game) :m_game(game), Command() {}
	~NewGame() = default;

	virtual void execute(sf::RenderWindow& window)override { m_game.runTheGame(); }
	virtual void unExecute(sf::RenderWindow& window) override {}

private:
	GameController& m_game;
};
