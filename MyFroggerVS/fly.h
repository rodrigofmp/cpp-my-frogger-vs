#pragma once
#include "bonus.h"
class Fly :
	public Bonus
{
public:
	Fly(int x, int y, Color color, int value);
	virtual ~Fly();
};

