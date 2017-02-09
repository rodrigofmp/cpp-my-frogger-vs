#include "object.h"
#include "frog.h"

Frog::Frog(int x, int y, Color color, int lifes)
	: Object(x, y, color)
{
	this->lifes = lifes;
}

Frog::~Frog()
{

}

int Frog::getLifes() const
{
	return lifes;
}

void Frog::removeLife()
{
	lifes--;
}