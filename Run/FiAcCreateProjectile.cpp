#include "FiAcCreateProjectile.h"
#include "SpProjectile.h"
#include "SpAcMove.h"
#include "Field.h"
#include <iostream>

FiAcCreateProjectile::FiAcCreateProjectile(int x, int y, Direction direction) : x(x), y(y), direction(direction), FieldAction(1)
{

}

void FiAcCreateProjectile::execute()
{
	unique_ptr<Sprite> newP = unique_ptr<SpProjectile>(new SpProjectile(x, y));
	unique_ptr<SpriteAction> move = unique_ptr<SpAcMove>(new SpAcMove(10, direction));
	newP->addAction(move);
	target->addSprite(newP);

	incTime();
}