#include "Field.h"

vector<unique_ptr<Sprite>> const& Field::getSprites() const
{
	return sprites;
}

vector<Sprite*> Field::getSpritesCopy()
{
	vector<Sprite*> output;
	for (auto const& sprite : sprites)
		output.push_back(sprite.get());
	return output;
}

void Field::addSprite(unique_ptr<Sprite> &sprite)
{ 
	// move gives ownership of the unique_ptr to the sprites vector
	this->sprites.push_back(move(sprite));
}

void Field::deleteSprite(unique_ptr<Sprite> &sprite)
{
	this->sprites.erase(
		remove(this->sprites.begin(), this->sprites.end(), sprite),
		this->sprites.end()
		);
}

void Field::deleteOutOfBoundSprites()
{
	this->sprites.erase(
		remove_if(
			this->sprites.begin(), 
			this->sprites.end(), 
			[](unique_ptr<Sprite> &sprite)
			{ 
				return sprite->getPosition().first + sprite->getSize().first < 0; 
			}
		),
		this->sprites.end()
		);
}

void Field::addAction(unique_ptr<FieldAction> &action)
{
	action->setTarget(this);
	this->actions.push_back(move(action));
}

void Field::deleteAction(unique_ptr<FieldAction> &action)
{
	this->actions.erase(
		remove(this->actions.begin(), this->actions.end(), action), 
		this->actions.end()
	);
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
		sprite->executeActions();
	}
}

void Field::executeCollisions()
{

}

int Field::updateScore()
{
	return 0;
}