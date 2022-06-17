#pragma once
#include "Command.h"
//-----------------------------------------------
class NoiseCommand :public Command {
public:
	NoiseCommand() :Command() {}
	~NoiseCommand() = default;
	virtual void execute(Display& d) override;
};
