#include "SpObstacle.h"


SpObstacle::SpObstacle(int width, int height, int x, int y)
{
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->state = 0;
	this->hp = 3;
}

const SpriteType::Type SpObstacle::getType() {
	return SpriteType::Type::OBSTACLE;
}
