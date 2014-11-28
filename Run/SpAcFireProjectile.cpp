#include "SpAcFireProjectile.h"
#include "config.h"
#include "Sprite.h"
#include "FiAcCreateProjectile.h"

/*We give a duration greater than 1 to the Action, in order to determine a firerate.
 Here, the sprite will only fire projectiles twice a second (roughly).*/
SpAcFireProjectile::SpAcFireProjectile(int fireRate) : fireRate(fireRate), SpriteAction((fireRate == 0)?1:-1) 
{
}

FieldAction* SpAcFireProjectile::execute()
{
	if (fireRate == 0)
	{
		auto XY = source->getPosition();

		FieldAction* createdProj = new FiAcCreateProjectile(XY.first, XY.second, Direction::RIGHT);
		incTime();

		return createdProj;
	}
	else if (getTime() % fireRate == 0)
	{
		auto XY = source->getPosition();
		
		FieldAction* createdProj = new FiAcCreateProjectile(XY.first, XY.second, Direction::RIGHT);
		incTime();

		return createdProj;
	}
	else
	{
		incTime();
		return nullptr;
	}
}