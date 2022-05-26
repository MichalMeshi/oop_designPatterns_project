#pragma once
class Move{
public:
	Move() {}
	virtual ~Move()=0{}
	virtual void move() = 0{}
protected:

};