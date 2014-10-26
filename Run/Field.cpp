#include "Field.h"

Field::Field()
{

}

Field::~Field()
{

}

vector<shared_ptr<Sprite>> Field::getSprites()
{
	return this->sprites;
}

void Field::addSprite(shared_ptr<Sprite> &sprite)
{
	this->sprites.push_back(sprite);
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