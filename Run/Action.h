#pragma once

class Action
{
protected:
	int duration = -1;
	int elapsedTime = 0;
public:
	Action(int duration = -1);
	virtual ~Action() = default;
	bool isOver();
};
