#include "mobile.h"

Mobile::Mobile(int x, int y, Color color, int speed, int length)
	: Object(x, y, color)
{
	this->speed = speed;
	this->length = length;
}

Mobile::~Mobile()
{

}

int Mobile::getSpeed() const
{
	return speed;
}

int Mobile::getLength() const
{
	return length;
}