#include "Sprite.h"
#include <iostream>

void Sprite::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

pair<int, int> Sprite::getPosition()
{
	return pair<int, int>(x, y);
}

void Sprite::setNPosition(int nx, int ny)
{
	this->nx = nx;
	this->ny = ny;
}

pair<int, int> Sprite::getNPosition()
{
	return pair<int, int>(nx, ny);
}

void Sprite::applyPosition()
{
	x = nx;
	y = ny;
}

void Sprite::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

pair<int, int> Sprite::getSize()
{
	return pair<int,int>(this->width,this->height);
}

void Sprite::setState(int state)
{
	this->state = state;
}

int Sprite::getState()
{
	return this->state;
}

void Sprite::addAction(pSpriteAction &spAction)
{
	spAction->setSource(this);
	spActions.push_back(move(spAction));
}

vector<pFieldAction> Sprite::executeActions()
{
	vector<pFieldAction> fieldActions;

	auto spAction = spActions.begin();
	while (spAction != spActions.end())
	{
		auto fAction = (*spAction)->execute();
		// FieldAction generation if it exists (for CreateProjectile mostly)
		if (fAction != nullptr)
		{
			pFieldAction fieldAction(fAction);
			fieldActions.push_back(move(fieldAction));
		}
		
		// Deleting action if it's over
		if ((*spAction)->isOver())
			spAction = spActions.erase(spAction);
		else
			spAction++;
    }
    return fieldActions; 
}

vector<pSpriteAction> const& Sprite::getActions() const
{
	return spActions;
}
