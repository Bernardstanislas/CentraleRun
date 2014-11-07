#include "FieldAction.h"

FieldAction::FieldAction(int duration) : Action(duration)
{

}

void FieldAction::setTarget(Field* target)
{
	this->target = target;
}