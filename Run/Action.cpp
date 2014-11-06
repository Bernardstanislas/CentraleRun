#include "Action.h"
#include <iostream>

Action::Action(int duration) : duration(duration)
{
	
}

bool Action::isOver()
{
	return (elapsedTime >= duration && duration != -1);
}