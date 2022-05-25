#pragma once
#include "Display.h"
class Command
{
public:
	Command()=default;
	virtual ~Command() = 0{}
	virtual void execute() = 0{}
private:

};


