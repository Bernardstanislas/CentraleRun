#include "SpriteAction.h"

SpriteAction::SpriteAction(int duration) : Action(duration)
{

}

void SpriteAction::setSource(Sprite* source)
{
	this->source = source;
}