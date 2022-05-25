#pragma once
class Move
{
public:
	Move() = default;
	virtual ~Move()=0;
	virtual void move() = 0;
private:

};