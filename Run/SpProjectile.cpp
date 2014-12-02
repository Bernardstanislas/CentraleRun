#include "SpProjectile.h"

SpProjectile::SpProjectile(int x, int y, int state)
{
	this->x = x;
	this->y = y;
	nx = x;
	ny = y;
	width = 1;
	height = 1;
	this->state = state;
}

const SpriteType::Type SpProjectile::getType() {
	return SpriteType::Type::PROJECTILE;
}
