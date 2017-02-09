#pragma once
#include "object.h"

class Bonus : public Object
{
private:
	int value;
public:
	Bonus(int x, int y, Color color, int value);
	~Bonus();

	int getValue() const;
};
