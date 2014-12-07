#include "Action.h"

int Action::getDuration()
{
	return duration;
}

int Action::getTime()
{
	return elapsedTime;
}

void Action::incTime()
{
	elapsedTime++;
}

Action::Action(int duration) : duration(duration)
{
	
}

bool Action::isOver()
{
	return (elapsedTime >= duration && duration != -1);
}

void Action::incDuration()
{
	duration++;
}