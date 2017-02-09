#include "bonus.h"

Bonus::Bonus(int x, int y, Color color, int value)
	: Object(x, y, color)
{
	this->value = value;
}

Bonus::~Bonus()
{

}

int Bonus::getValue() const
{
	return value;
}

