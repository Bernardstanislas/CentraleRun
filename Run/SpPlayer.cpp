#include "SpPlayer.h"


SpPlayer::SpPlayer()
{
	width = 1;
	height = 2;
	x = 3;
	y = 0;
	nx = 3;
	ny = 0;
	state = 1;
	hp = 1;
}

const SpriteType::Type SpPlayer::getType() {
	return SpriteType::Type::PLAYER;
}
