#include "FiAcMove.h"
#include "Field.h"
#include "SpPlayer.h"

FiAcMove::FiAcMove() : FieldAction()
{

}

void FiAcMove::execute()
{
	for (auto const& sprite : target->getSprites())
	{
		if (dynamic_cast<SpPlayer*>(sprite.get()) == nullptr)
		{
			auto XY = sprite->getNPosition(); // Position will already be updated by previous SpMoves
			sprite->setNPosition(XY.first - target->getSpeed(), XY.second);
		}
	}
}