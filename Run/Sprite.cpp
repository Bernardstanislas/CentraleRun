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

vector<unique_ptr<SpriteAction>>::iterator Sprite::deleteAction(unique_ptr<SpriteAction> &spAction)
{
    return this->spActions.erase(
        std::remove(this->spActions.begin(), this->spActions.end(), spAction),
        this->spActions.end());
}

vector<unique_ptr<FieldAction>> Sprite::executeActions()
{
    //this section doesn't work. We'll fix it asap, but somewhere else.
	
	vector<unique_ptr<FieldAction>> fieldActions;
	for (auto &spAction = spActions.begin(); spAction != spActions.end(); spAction++)
	{
        unique_ptr<FieldAction> fieldAction(spAction->execute());
        // To do when the FieldAction class is ready: only add if fieldAction is not empty/null
        fieldActions.push_back(move(fieldAction));
		if (spAction->isOver()){
			spAction = deleteAction(spAction);
		}
    }
    return fieldActions; 
	
	
	/*
	for (auto const& action : spActions)
	{
		action->execute();
		action->isOver();
	}
	return vector<unique_ptr<FieldAction>>();*/
}

vector<unique_ptr<SpriteAction>> const& Sprite::getActions() const
{
	return spActions;
}
