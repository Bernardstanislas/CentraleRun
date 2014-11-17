#include "FiAcCreateProjectile.h"
#include "SpProjectile.h"
#include "SpAcMove.h"
#include "Field.h"
#include <iostream>

FiAcCreateProjectile::FiAcCreateProjectile(int x, int y) : x(x), y(y), FieldAction(1)
{

}

void FiAcCreateProjectile::execute()
{
	int t = this->getTime();
	int d = this->getDuration();

	//if structure not mandatory any longer.
	if ( t < d){
		
		unique_ptr<Sprite> newP = unique_ptr<SpProjectile>(new SpProjectile(x, y));
		unique_ptr<SpriteAction> move = unique_ptr<SpAcMove>(new SpAcMove(5));
		newP->addAction(move);
		target->addSprite(newP);

		incTime();
	}

}