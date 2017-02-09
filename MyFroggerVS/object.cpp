#include "object.h"

Object::Object(int x, int y, Color color)
{
	this->x = x;
	this->y = y;
	this->color = color;
}

Object::~Object()
{

}

int Object::getX() const
{
	return x;
}

int Object::getY() const
{
	return y;
}

Color Object::getColor() const
{
	return color;
}

void Object::setX(int const x)
{
	this->x = x;
}

void Object::setY(int const y)
{
	this->y = y;
}