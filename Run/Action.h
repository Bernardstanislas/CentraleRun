#pragma once

class Action
{
protected:
	virtual int duration;
	virtual int elapsedTime;
public:
	virtual void execute() = 0;
	bool isOver();
};
