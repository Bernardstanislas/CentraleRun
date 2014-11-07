#pragma once

class Action
{
private:
	int duration = -1;
	int elapsedTime = 0;
protected:
	int getDuration();
	int getTime();
	void incTime();
public:
	Action(int duration = -1);
	virtual ~Action() = default;
	bool isOver();
};
