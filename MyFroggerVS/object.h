#pragma once
#include "commons.h"

class Object
{
private:
	int x, y;
	Color color;
public:
	Object(int x, int y, Color color);
	virtual ~Object();

	int getX() const;
	int getY() const;
	Color getColor() const;

	void setX(int const x);
	void setY(int const y);
};
