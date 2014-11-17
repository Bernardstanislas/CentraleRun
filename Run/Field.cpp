#include "Field.h"

Field::Field() {
	sprites = vector<unique_ptr<Sprite>>();
	actions = vector<unique_ptr<FieldAction>>();
	collisionHandler = unique_ptr<CollisionHandler>(new CollisionHandler());

	for (int i = 0; i < SEQ_C0_COUNT; i++)
	{
		TerrainSequence seqTest;
		seqTest.ParseFile("terrain0-" + to_string(i) + ".txt");
		seqTest.FillData();
		sequences.push_back(make_pair(0, move(seqTest.getData())));
	}
	
}

vector<TerrainGrid> Field::getSequence(int complexity)
{
	return sequences[rand() % SEQ_C0_COUNT].second;
}

unique_ptr<Sprite> Field::MakeRegularBlock(TerrainGrid &block)
{
	int y = block.begin()->first;
	int x = block.begin()->second.begin()->first;
	int height = block.size();
	int width = block.begin()->second.size();

	return make_unique<SpObstacle>(width, height, x+WINDOW_BLOCK_WIDTH, y);
}

int Field::getSpeed()
{
	return speed;
}

void Field::setSpeed(int speed)
{
	this->speed = speed;
}

void Field::incSpeed()
{
	speed++;
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
	auto action = actions.begin();
	while (action != actions.end())
	{
		(*action)->execute();
		// Deleting action if it's over
		if ((*action)->isOver())
			action = actions.erase(action);
		else
			action++;
	}
}

void Field::executeSpriteActions()
{
	for (auto const& sprite : sprites)
	{
		vector<unique_ptr<FieldAction>> fieldActions = sprite->executeActions();

		if (!fieldActions.empty()){

			for (auto &fAc : fieldActions){
				this->addAction(fAc);
			}
		}
	}
}

void Field::executeCollisions()
{
	for (unsigned int index1 = 0; index1 < sprites.size(); ++index1)
	{
		for (unsigned int index2 = index1 + 1; index2 < sprites.size(); ++index2) {
			unsigned int const indexDifference = index2 - index1;
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
