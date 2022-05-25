#pragma once
#include "SmartMove.h"
class SmartMove :public Move
{
public:
	SmartMove() = default;
	~SmartMove() = default;
	virtual void move() override {}
};