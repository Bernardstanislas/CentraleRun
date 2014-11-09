#include "SpProjectile.h"

SpProjectile::SpProjectile(int x, int y)
{
	this->x = x;
	this->y = y;
	this->width = 1;
	this->height = 1;
	this->state = 1;
}

const SpriteType::Type SpProjectile::getType() {
	return SpriteType::Type::PROJECTILE;
}
