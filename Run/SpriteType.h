#pragma once

#include <string>

class SpriteType
{
public:
	enum class Type {
		PLAYER,
		OBSTACLE,
		PROJECTILE,
		BONUS,
		UNKNOWN
	};
	static Type getType(std::string type);
};
