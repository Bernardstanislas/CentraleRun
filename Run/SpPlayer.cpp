#include "SpPlayer.h"


SpPlayer::SpPlayer()
{
	this->width = 1;
	this->height = 2;
	this->x = 3;
	this->y = 0;
	this->state = 1;
	this->hp = 1;
}

const SpriteType::Type SpPlayer::getType() {
	return SpriteType::Type::PLAYER;
}
