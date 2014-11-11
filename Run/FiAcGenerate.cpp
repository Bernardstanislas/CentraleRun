#include "FiAcGenerate.h"
#include "Sprite.h"
#include "SpObstacle.h"
#include "Field.h"
#include <iostream>
#include "SpAcMove.h"

FiAcGenerate::FiAcGenerate() : FieldAction()
{

}


void FiAcGenerate::createSequence()
{
	vector<unique_ptr<Sprite>> sequence;
	for (int i = 0; i < ceil((float)SEQUENCE_SIZE / 20); i++)
	{
		sequence.push_back(make_unique<SpObstacle>(1, 1));
	}

	if (complexity > 0)
		for (int i = 0; i < ceil((float)SEQUENCE_SIZE / 40); i++)
		{
			sequence.push_back(make_unique<SpObstacle>(2, 2));
		}

	if (complexity > 1)
		for (int i = 0; i < ceil((float)SEQUENCE_SIZE / 40); i++)
		{
			unique_ptr<Sprite> o = make_unique<SpObstacle>(1, 1);
			unique_ptr<SpriteAction> m = make_unique<SpAcMove>(0, 1, 5);
			o->addAction(m);
			sequence.push_back(move(o));
		}

	if (complexity > 2)
		for (int i = 0; i < ceil((float)SEQUENCE_SIZE / 40); i++)
		{
			unique_ptr<Sprite> o = make_unique<SpObstacle>(2, 2);
			unique_ptr<SpriteAction> m = make_unique<SpAcMove>(1, 0, 3);
			o->addAction(m);
			sequence.push_back(move(o));
		}
	
	for (auto &obstacle : sequence)
	{
		obstacle->setPosition(WINDOW_BLOCK_WIDTH + rand() % SEQUENCE_SIZE, rand() % 5);
		target->addSprite(obstacle);
	}
}

void FiAcGenerate::execute()
{
	if (blockCount == 0)
		createSequence();

	target->deleteOutOfBoundSprites();

	blockCount += target->getSpeed();
	if (blockCount >= SEQUENCE_SIZE)
		blockCount = 0;

	incTime();

	if (getTime() % COMPLEXITY_INC_TIME == 0)
		complexity++;

	if (getTime() % SPEED_INC_TIME == 0 && target->getSpeed() < MAX_SPEED)
		target->incSpeed();
}