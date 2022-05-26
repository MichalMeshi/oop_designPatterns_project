#pragma once
#include "Move.h"
class SimpleMove :public Move
{
public:
	SimpleMove() {}
	~SimpleMove() {}
	virtual void move() override {}
private:
};