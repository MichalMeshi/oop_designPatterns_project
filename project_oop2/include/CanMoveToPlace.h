#pragma once
class CanMoveToPlace
{
public:
	CanMoveToPlace() = default;
	virtual ~CanMoveToPlace()=0{}
	virtual bool ableToMoveToPlace()=0{ return true; }
private:

};