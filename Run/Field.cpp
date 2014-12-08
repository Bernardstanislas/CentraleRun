#include "Field.h"
#include "SpAcFireProjectile.h"
#include "SpAcMove.h"

Field::Field() 
{
	sprites = vector<pSprite>();
	actions = vector<pFieldAction>();
	collisionHandler = pCollisionHandler(new CollisionHandler(this));

	for (int h = 0; h < 2; h++)
		for (int i = 0; i < SEQ_C0_COUNT; i++)
		{
			TerrainSequence seqTest;
			seqTest.ParseFile("terrain" + to_string(h) + "-" + to_string(i) + ".txt");
			seqTest.FillData();
			sequences.push_back(make_pair(h, move(seqTest.getData())));
		}
}

vector<TerrainGrid> Field::getSequence(int complexity)
{
	//int c = (complexity > 1) ? 1 : complexity;
	//return sequences[rand() % ((c+1)*SEQ_C0_COUNT)].second;
	return sequences[0].second;
}

pSprite Field::MakeRegularBlock(TerrainGrid &block)
{
	int y = block.begin()->first;
	int x = block.begin()->second.begin()->first;
	int height = block.size();
	int width = block.begin()->second.size();
	pSprite output = make_unique<SpObstacle>(width, height, x+WINDOW_BLOCK_WIDTH, y);

	char fireDirection = block.begin()->second.begin()->second.first;
	if (fireDirection != 'X')
	{
		output->setState(4); // Red block

		Direction direction;
		switch (fireDirection)
		{
		case 'U':
			direction = Direction::UP;
			break;
		case 'D':
			direction = Direction::DOWN;
			break;
		case 'L':
			direction = Direction::LEFT;
			break;
		case 'R':
			direction = Direction::RIGHT;
			break;
		}
		pSpriteAction fire = make_unique<SpAcFireProjectile>(direction, FRAMERATE/2);
		output->addAction(fire);
	}
	return move(output);
}

pSprite Field::MakeMovingBlock(TerrainGrid &block)
{
	auto movingBlock = block;

	auto y = movingBlock.begin();
	while (y != movingBlock.end())
	{
		auto x = y->second.begin();
		while (x != y->second.end())
		{
			if (x->second.first == '+')
				y->second.erase(x++);
			else
				x++;
		}
		if (y->second.size() == 0)
			movingBlock.erase(y++);
		else
			y++;
	}

	auto output = MakeRegularBlock(movingBlock);
	Direction direction;
	bool isDirectionUp = false;
	int loopTime = 0;

	auto y2 = block.begin();
	while (y2 != block.end())
	{
		if (y2->second.begin()->second.first == '+')
		{
			isDirectionUp = true;
			loopTime++;
		}
		y2++;
	}

	if (isDirectionUp)
		direction = Direction::UP;
	else
	{
		direction = Direction::RIGHT;
		auto x2 = block.begin()->second.begin();
		while (x2 != block.begin()->second.end())
		{
			if (x2->second.first == '+')
				loopTime++;
			x2++;
		}
	}

	pSpriteAction loopMove = make_unique<SpAcMove>(1, direction, loopTime);
	output->addAction(loopMove);
	return move(output);
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

vector<pSprite> const& Field::getSprites() const
{
	return sprites;
}

void Field::addSprite(pSprite &sprite)
{
	// move gives ownership of the unique_ptr to the sprites vector
	this->sprites.push_back(move(sprite));
}

void Field::deleteSprite(pSprite &sprite)
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
			[](pSprite &sprite)
			{
				return sprite->getPosition().first + sprite->getSize().first < -10;
			}
		),
		this->sprites.end()
		);
}

void Field::applySpritesPosition()
{
	for (auto &sprite : sprites)
		sprite->applyPosition();
}

void Field::addAction(pFieldAction &action)
{
	action->setTarget(this);
	this->actions.push_back(move(action));
}

void Field::deleteAction(pFieldAction &action)
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

//this function executes the SpriteActions and gets the FieldActions created.
//Those fieldActions are then put in the Field action list.
void Field::executeSpriteActions()
{
	for (auto const& sprite : sprites)
	{
		vector<pFieldAction> fieldActions = sprite->executeActions();

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
