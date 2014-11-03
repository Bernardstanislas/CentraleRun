#include "Action.h"

bool Action::isOver()
{
	return (elapsedTime >= duration && duration != -1);
}