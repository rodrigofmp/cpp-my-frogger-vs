#include "sinkable.h"
#include "commons.h"

Sinkable::Sinkable(int x, int y, Color color, int speed, int length)
	: Mobile(x, y, color, speed, length)
{
	this->state = sunken;
}

Sinkable::~Sinkable()
{

}

void Sinkable::setState(SinkableStates const state)
{
	this->state = state;
}
