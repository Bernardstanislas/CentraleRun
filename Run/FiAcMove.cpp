#include "FiAcMove.h"
#include "Field.h"
#include "SpPlayer.h"

FiAcMove::FiAcMove(int speed) : speed(speed)
{
	duration = -1;
}

void FiAcMove::execute()
{
	for (auto const& sprite : target->getSprites())
	{
		if (dynamic_cast<SpPlayer*>(sprite.get()) == nullptr)
		{
			auto XY = sprite->getPosition();
			sprite->setPosition(XY.first - speed, XY.second);
		}
	}
}