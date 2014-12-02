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
	int state;
	if (direction == Direction::UP || direction == Direction::DOWN)
		state = 3;
	else
		state = 2;
	unique_ptr<Sprite> newP = unique_ptr<SpProjectile>(new SpProjectile(x, y, state));
	unique_ptr<SpriteAction> move = unique_ptr<SpAcMove>(new SpAcMove(10, direction));
	newP->addAction(move);
	newP->executeNewActions();
	target->addSprite(newP);

	incTime();
}