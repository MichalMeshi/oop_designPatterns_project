#pragma once
#include "SimpleMove.h"
class SimpleMove :public Move
{
public:
	SimpleMove() = default;
	~SimpleMove() = default;
	virtual void move() override {}
};