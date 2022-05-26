#pragma once
#include "Move.h"
class MoveFar:public Move
{
public:
	MoveFar() {}
	~MoveFar() {}
	virtual void move() override{}
};