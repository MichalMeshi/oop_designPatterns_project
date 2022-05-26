#pragma once
#include "Move.h"
class SmartMove :public Move
{
public:
	SmartMove() {}
	~SmartMove() {}
	virtual void move() override {}
};