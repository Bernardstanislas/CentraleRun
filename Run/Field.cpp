#include "Field.h"

Field::Field() {
	sprites = vector<unique_ptr<Sprite>>();
	actions = vector<unique_ptr<FieldAction>>();
	collisionHandler = unique_ptr<CollisionHandler>(new CollisionHandler());
}

int Field::getSpeed()
{
	return speed;
}

void Field::setSpeed(int speed)
{
	this->speed = speed;
}

vector<unique_ptr<Sprite>> const& Field::getSprites() const
{
	return sprites;
}

vector<SpriteView> Field::getSpritesView()
{
	vector<SpriteView> output;
	for (auto const& sprite : sprites)
		output.push_back(SpriteView(sprite.get(), sprite->getSize().first, sprite->getSize().second, sprite->getPosition().first, sprite->getPosition().second));

	return output;
}

void Field::addSprite(unique_ptr<Sprite> &sprite)
{
	// move gives ownership of the unique_ptr to the sprites vector
	this->sprites.push_back(move(sprite));
}

void Field::deleteSprite(unique_ptr<Sprite> &sprite)
{
	this->sprites.erase(
		remove(this->sprites.begin(), this->sprites.end(), sprite),
		this->sprites.end()
		);
}

void Field::deleteOutOfBoundSprites()
{
	this->sprites.erase(
		remove_if(
			this->sprites.begin(),
			this->sprites.end(),
			[](unique_ptr<Sprite> &sprite)
			{
				return sprite->getPosition().first + sprite->getSize().first < -10;
			}
		),
		this->sprites.end()
		);
}

void Field::addAction(unique_ptr<FieldAction> &action)
{
	action->setTarget(this);
	this->actions.push_back(move(action));
}

void Field::deleteAction(unique_ptr<FieldAction> &action)
{
	this->actions.erase(
		remove(this->actions.begin(), this->actions.end(), action),
		this->actions.end()
	);
}


void Field::executeFieldActions()
{
	for (auto const& action : actions)
	{
		action->execute();
		action->isOver();
	}
}

void Field::executeSpriteActions()
{
	for (auto const& sprite : sprites)
	{
		sprite->executeActions();
	}
}

void Field::executeCollisions()
{
	for (auto index1 = 0; index1 < sprites.size(); ++index1)
	{
		for (auto index2 = index1 + 1; index2 < sprites.size(); ++index2) {
			int const indexDifference = index2 - index1;
			if (indexDifference > 0) {
				this->collisionHandler->executeCollider(sprites[index1], sprites[index2]);
			}
		}
	}
}

int Field::updateScore()
{
	return 0;
}
