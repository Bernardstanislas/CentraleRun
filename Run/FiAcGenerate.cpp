#include "FiAcGenerate.h"
#include "Sprite.h"
#include "SpObstacle.h"
#include "Field.h"

FiAcGenerate::FiAcGenerate(int speed) : speed(speed)
{
	duration = -1;
}


void FiAcGenerate::execute()
{
	if (blockCount == 0)
	{
		unique_ptr<Sprite> o1 = unique_ptr<SpObstacle>(new SpObstacle(3, 3, SEQUENCE_SIZE, 1));
		unique_ptr<Sprite> o2 = unique_ptr<SpObstacle>(new SpObstacle(2, 2, SEQUENCE_SIZE + 10, 2));
		unique_ptr<Sprite> o3 = unique_ptr<SpObstacle>(new SpObstacle(5, 2, SEQUENCE_SIZE + 20, 0));
		unique_ptr<Sprite> o4 = unique_ptr<SpObstacle>(new SpObstacle(10, 3, SEQUENCE_SIZE + 28, 1));
		unique_ptr<Sprite> o5 = unique_ptr<SpObstacle>(new SpObstacle(2, 1, SEQUENCE_SIZE + 51, 3));

		target->addSprite(o1);
		target->addSprite(o2);
		target->addSprite(o3);
		target->addSprite(o4);
		target->addSprite(o5);
	}

	target->deleteOutOfBoundSprites();

	blockCount += speed;
	if (blockCount >= SEQUENCE_SIZE)
		blockCount = 0;
}