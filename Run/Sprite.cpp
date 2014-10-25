#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(int x, int y, int width, int height, int state) : x(x), y(y), width(width), height(height), state(state)
{

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

void Sprite::addAction(Action &action)
{

}

void Sprite::deleteAction(unique_ptr<Action> action)
{

}

void Sprite::executeActions()
{

}
