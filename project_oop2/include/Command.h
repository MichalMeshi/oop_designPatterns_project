#pragma once
#include "Display.h"
//----------------------------------------------
class Command {
public:
	Command()=default;
	virtual ~Command() = 0{}
	virtual void execute(Display& d) = 0{}
private:
};