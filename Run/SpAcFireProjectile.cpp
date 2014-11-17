#include "SpAcFireProjectile.h"
#include "config.h"
#include "Sprite.h"
#include "FiAcCreateProjectile.h"

/*We give a duration greater than 1 to the Action, in order to determine a firerate.
 Here, the sprite will only fire projectiles twice a second (roughly).*/
SpAcFireProjectile::SpAcFireProjectile() : SpriteAction(FRAMERATE/2) 
{
}

FieldAction* SpAcFireProjectile::execute()
{
	if (getTime() < 1)
	{
		auto XY = source->getPosition();
		
		//this should work.
		//unique_ptr<FieldAction> createdProj = unique_ptr<FiAcCreateProjectile>(new FiAcCreateProjectile(XY.first, XY.second));
		FieldAction* createdProj = new FiAcCreateProjectile(XY.first, XY.second);
		incTime();

		return createdProj;
		// I don't get the right type, which is not normal
		//return &createdProj;
	}
	else
	{
		incTime();
		return nullptr;
	}
}