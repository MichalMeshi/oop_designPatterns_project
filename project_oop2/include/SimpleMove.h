#pragma once
#include Move;
class SimpleMove :public Move
{
public:
	SimpleMove() = default;
	~SimpleMove() = default;
	virtual void move() override {}
};