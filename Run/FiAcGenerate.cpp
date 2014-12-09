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
	for (auto obstacle : target->getSequence(complexity))
	{
		if (obstacle.begin()->second.begin()->second.second == 'X')
		{
			auto sp = target->MakeRegularBlock(obstacle);
			target->addSprite(sp);
		}
		else
		{
			auto sp = target->MakeMovingBlock(obstacle);
			target->addSprite(sp);
		}
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
