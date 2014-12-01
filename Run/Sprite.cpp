#include "Sprite.h"

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
	this->spActions.push_back(move(spAction));
}

void Sprite::deleteAction(unique_ptr<SpriteAction> &spAction)
{
	this->spActions.erase(
        std::remove(this->spActions.begin(), this->spActions.end(), spAction),
        this->spActions.end());
}

vector<unique_ptr<FieldAction>> Sprite::executeActions()
{	
	vector<unique_ptr<FieldAction>> fieldActions;

	auto spAction = spActions.begin();
	while (spAction != spActions.end())
	{
		auto fAction = (*spAction)->execute();
		// FieldAction generation if it exists (for CreateProjectile mostly)
		if (fAction != nullptr)
		{
			unique_ptr<FieldAction> fieldAction(fAction);
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

vector<unique_ptr<SpriteAction>> const& Sprite::getActions() const
{
	return spActions;
}

unique_ptr<SpriteAction> const& Sprite::getAction(unique_ptr<SpriteAction> &action) const
{
	return *find(spActions.begin(), spActions.end(), action);
}
