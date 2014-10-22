#pragma once
#include "FieldAction.h"
class FiAcCreateProjectile :
	public FieldAction
{
protected:
	int duration;
	int elapsedTime;
public:
	FiAcCreateProjectile();
	~FiAcCreateProjectile();
	void execute();
};
