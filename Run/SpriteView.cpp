#include "SpriteView.h"

SpriteView::SpriteView(Sprite* sprite, int width, int height, int x, int y) : sprite(sprite), width(width), height(height), x(x), y(y)
{

}

pair<int, int> SpriteView::getPosition()
{
	return pair<int, int>(x, y);
}

pair<int, int> SpriteView::getSize()
{
	return pair<int, int>(width, height);
}