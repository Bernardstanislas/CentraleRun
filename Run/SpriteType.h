#pragma once

#include <string>

class SpriteType
{
public:
	enum class Type {
		PLAYER,
		OBSTACLE,
		PROJECTILE,
		BONUS
	};
	static Type getType(std::string type);
};
