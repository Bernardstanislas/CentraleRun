#include "SpProjectile.h"


SpProjectile::SpProjectile()
{
}

SpProjectile::SpProjectile(int x, int y, int width, int height, int state)
    : Sprite(x, y, width, height, state)
{
}

SpProjectile::~SpProjectile()
{
}
