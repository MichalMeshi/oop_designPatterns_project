#pragma once
#include Move;
class SmartMove :public Move
{
public:
	SmartMove() = default;
	~SmartMove() = default;
	virtual void move() override {}
};