#pragma once
#include "Move.h"
class MoveFar:public Move
{
public:
	MoveFar() = default;
	~MoveFar() = default;
	virtual void move() override{}
};