#include "Sprite.h"
#include <iostream>

void Sprite::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

pair<int, int> Sprite::getPosition()
{
	return pair<int, int>(this->x, this->y);
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

void Sprite::addAction(unique_ptr<SpriteAction> &spAction)
{
	spAction->setSource(this);
	spActions.push_back(make_pair(move(spAction),false));
}

vector<unique_ptr<FieldAction>> Sprite::executeActions()
{
	vector<unique_ptr<FieldAction>> fieldActions;

	for (auto &action : spActions)
	{
		action.second = false;
	}

	auto spAction = spActions.begin();
	while (spAction != spActions.end())
	{
		auto fAction = spAction->first->execute();
		// FieldAction generation if it exists (for CreateProjectile mostly)
		if (fAction != nullptr)
		{
			unique_ptr<FieldAction> fieldAction(fAction);
			fieldActions.push_back(move(fieldAction));
		}
		
		spAction->second = true;

		// Deleting action if it's over
		if (spAction->first->isOver())
			spAction = spActions.erase(spAction);
		else
			spAction++;
    }
    return fieldActions; 
}

void Sprite::executeNewActions()
{
	auto spAction = spActions.begin();
	while (spAction != spActions.end())
	{
		if (!spAction->second)
		{
			cout << "lol" << endl;
 			spAction->first->execute();
			spAction->second = true;

			// Deleting action if it's over
			if (spAction->first->isOver())
				spAction = spActions.erase(spAction);
			else
				spAction++;
		}
		else
			spAction++;
	}
}

vector<pair<unique_ptr<SpriteAction>,bool>> const& Sprite::getActions() const
{
	return spActions;
}
