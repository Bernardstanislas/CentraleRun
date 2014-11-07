#include "FiAcCreateProjectile.h"
#include "SpProjectile.h"
#include "SpAcMove.h"
#include "Field.h"

FiAcCreateProjectile::FiAcCreateProjectile(int x, int y) : x(x), y(y), FieldAction()
{

}

void FiAcCreateProjectile::execute()
{
	unique_ptr<Sprite> newP = unique_ptr<SpProjectile>(new SpProjectile(x,y));
	unique_ptr<SpriteAction> move = unique_ptr<SpAcMove>(new SpAcMove(3));
	newP->addAction(move);
	target->addSprite(newP);

	incTime();
}