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

void Field::addSprite(Sprite &sprite)
{
	this->sprites.push_back(make_shared<Sprite>(sprite));
}

void Field::addAction(Action &action)
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