#include "FiAcGenerate.h"
#include "Sprite.h"
#include "SpObstacle.h"
#include "Field.h"

FiAcGenerate::FiAcGenerate(int complexity) : complexity(complexity), FieldAction()
{

}


void FiAcGenerate::createSequence()
{
	unique_ptr<Sprite> o1 = unique_ptr<SpObstacle>(new SpObstacle(20, 3, WINDOW_BLOCK_WIDTH, 1));
	unique_ptr<Sprite> o5 = unique_ptr<SpObstacle>(new SpObstacle(20, 5, WINDOW_BLOCK_WIDTH + 10, 5));

	target->addSprite(o1);
	target->addSprite(o5);
}

void FiAcGenerate::execute()
{
	if (blockCount == 0)
		createSequence();

	target->deleteOutOfBoundSprites();

	blockCount += target->getSpeed();
	if (blockCount >= SEQUENCE_SIZE)
		blockCount = 0;
}