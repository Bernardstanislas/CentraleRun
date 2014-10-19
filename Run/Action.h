#pragma once

class Action
{
protected:
	int duration;
	int elapsedTime;
public:
	Action(int duration);
	~Action();
	void execute();
	bool isOver();
};

