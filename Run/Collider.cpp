#include "Collider.h"

pair<SpriteType::Type, SpriteType::Type> Collider::getSignature()
{
	return pair<SpriteType::Type, SpriteType::Type>(SpriteType::Type::PLAYER, SpriteType::Type::PLAYER);
}
