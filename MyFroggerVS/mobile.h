#pragma once
#include "object.h"

class Mobile : public Object
{
private:
	int speed, length;
public:
	Mobile(int x, int y, Color color, int speed, int length);
	~Mobile();

	int getSpeed() const;
	int getLength() const;
};