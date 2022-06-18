#pragma once
#include "Command.h"
//-----------------------------------------------
class ShowInstructionsCommand:public Command{
public:
	ShowInstructionsCommand();
	~ShowInstructionsCommand() = default;
	virtual void execute(Display& d) override;
private:
	Display m_instructions;
	Display m_back;

	void draw() { m_instructions.draw(); m_back.draw(); }

};
