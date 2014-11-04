#include "Sprite.h"

Sprite::Sprite()
{
    this->spActions = vector<unique_ptr<SpriteAction>>();
}

Sprite::Sprite(int x, int y, int width, int height, int state) :
    x(x), y(y), width(width), height(height), state(state)
{
    this->spActions = vector<unique_ptr<SpriteAction>>();
}

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
    this->spActions.push_back(move(spAction));
}

void Sprite::deleteAction(unique_ptr<SpriteAction> spAction)
{
    this->spActions.erase(
        std::remove(this->spActions.begin(), this->spActions.end(), spAction),
        this->spActions.end());
}

vector<unique_ptr<FieldAction>> Sprite::executeActions()
{
    vector<unique_ptr<FieldAction>> fieldActions;
    for (auto & spAction : this->spActions) {
        unique_ptr<FieldAction> fieldAction(spAction->execute(this));
        // To do when the FieldAction class is ready: only add if fieldAction is not empty/null
        fieldActions.push_back(move(fieldAction));
    }
    return fieldActions;
}
