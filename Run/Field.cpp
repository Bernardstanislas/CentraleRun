#include "Field.h"

Field::Field()
{

}

Field::~Field()
{

}

vector<unique_ptr<Sprite>> const& Field::getSprites() const
{
	return sprites;
}

void Field::addSprite(unique_ptr<Sprite> &sprite)
{ 
	// move gives ownership of the unique_ptr to the sprites vector
	this->sprites.push_back(move(sprite));
}

void Field::addAction(unique_ptr<Action> &action)
{

}

void Field::executeFieldActions()
{

}

void Field::executeSpriteActions()
{

}

void Field::executeCollisions()
{

}

int Field::updateScore()
{
	return 0;
}