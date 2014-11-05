#include "FiAcMove.h"
#include "Field.h"
#include "SpPlayer.h"

FiAcMove::FiAcMove(int speed) : speed(speed)
{
	duration = -1;
}

void FiAcMove::execute()
{
	for (auto const& sprite : target->getSprites()) // Erreur ici
	{
		if (typeid(sprite) != typeid(SpPlayer))
		{
			auto XY = sprite->getPosition();
			sprite->setPosition(XY.first - 1, XY.second);
		}
	}
}