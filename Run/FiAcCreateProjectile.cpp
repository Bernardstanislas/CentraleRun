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
	pSprite newP = make_unique<SpProjectile>(x, y, state);
	pSpriteAction move = make_unique<SpAcMove>(PROJECTILE_SPEED, direction);
	newP->addAction(move);

	// Setting up manually the next projectile position. 
	// The next ones will be handled by the move action, but not this one since it won't be executed before the next frame.
	int nx = x;
	int ny = y;

	switch (direction)
	{
	case Direction::DOWN:
		ny -= PROJECTILE_SPEED;
		break;
	case Direction::UP:
		ny += PROJECTILE_SPEED;
		break;
	case Direction::LEFT:
		nx -= PROJECTILE_SPEED;
		break;
	case Direction::RIGHT:
		nx += PROJECTILE_SPEED;
		break;
	}
	nx -= target->getSpeed();

	newP->setNPosition(nx, ny);
	target->addSprite(newP);

	incTime();
}