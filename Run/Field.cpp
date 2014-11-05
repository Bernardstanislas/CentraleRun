#include "Field.h"

vector<unique_ptr<Sprite>> const& Field::getSprites() const
{
	return sprites;
}

void Field::addSprite(unique_ptr<Sprite> &sprite)
{ 
	// move gives ownership of the unique_ptr to the sprites vector
	this->sprites.push_back(move(sprite));
}

void Field::deleteSprite(int position)
{
	this->sprites.erase(sprites.begin() + position);
}

void Field::addAction(unique_ptr<FieldAction> &action)
{
	action->setTarget(this);
	this->actions.push_back(move(action));
}

void Field::deleteAction(int position)
{
	this->actions.erase(actions.begin() + position);
}

void Field::executeFieldActions()
{
	for (auto const& action : actions)
	{
		action->execute();
		action->isOver();
	}
}

void Field::executeSpriteActions()
{
	for (auto const& sprite : sprites)
	{
		for (auto const& action : sprite->getActions())
		{
			action->execute();
			action->isOver();
		}
	}
}

void Field::executeCollisions()
{

}

int Field::updateScore()
{
	return 0;
}