#pragma once
#include "mobile.h"

class Automobile : public Mobile
{
public:
	Automobile(int x, int y, Color color, int speed, int length);
	~Automobile();
};