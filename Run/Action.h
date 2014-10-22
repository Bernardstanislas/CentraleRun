#pragma once

class Action
{
protected:
	int duration;
	int elapsedTime;
public:
	virtual void execute() = 0;
	bool isOver();
};
