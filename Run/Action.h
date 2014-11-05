#pragma once

class Action
{
protected:
	int duration;
	int elapsedTime;
public:
	virtual ~Action() = default;
	bool isOver();
};
