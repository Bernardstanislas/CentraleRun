#pragma once
#include "FieldAction.h"
class FiAcMove :
	public FieldAction
{
protected:
	int speed;
public:
	FiAcMove(int speed);
	void execute();
};
