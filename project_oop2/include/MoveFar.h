#pragma once
#include Move;
class MoveFar:public Move
{
public:
	MoveFar() = default;
	~MoveFar() = default;
	virtual void move() override{}
};