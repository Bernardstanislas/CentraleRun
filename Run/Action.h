#pragma once

class Action
{
protected:
	int duration;
	int elapsedTime;
public:
	bool isOver();
};
