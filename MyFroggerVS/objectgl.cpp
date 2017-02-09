#include "objectgl.h"

void ObjectGL::Draw(const Object& object, const Board& board)
{
	GLfloat pointA_X = (object.getX() - 1) * board.getBlockSize();
	GLfloat pointB_Y = (object.getY() - 1) * board.getBlockSize();

	GLfloat pointA_Y = pointB_Y + board.getBlockSize();
	GLfloat pointB_X = pointA_X + board.getBlockSize();

	GLfloat pointC_X = pointA_X;
	GLfloat pointC_Y = pointB_Y;

	GLfloat pointD_X = pointB_X;
	GLfloat pointD_Y = pointA_Y;
	
	glBegin(GL_QUADS);
	glColor3f(object.getColor().red, object.getColor().green, object.getColor().blue);
	glVertex2f(pointA_X, pointA_Y);
	glVertex2f(pointC_X, pointC_Y);
	glVertex2f(pointB_X, pointB_Y);	
	glVertex2f(pointD_X, pointD_Y);
	glEnd();
};