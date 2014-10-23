#include "SpriteType.h"

SpriteType::Type SpriteType::getType(std::string type)
{
	if (type == "SpPlayer") return Type::PLAYER;
	else if (type == "SpObstacle") return Type::OBSTACLE;
	else if (type == "SpProjectile") return Type::PROJECTILE;
	else if (type == "SpBonus") return Type::BONUS;
}