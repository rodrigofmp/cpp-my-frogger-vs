#include "froggl.h"

void FrogGL::Draw(const Frog& frog, const Board& board)
{
	GLfloat pointA_X = (frog.getX() - 1) * board.getBlockSize();
	GLfloat pointB_Y = (frog.getY() - 1) * board.getBlockSize();
	GLfloat pointC_X = pointA_X + board.getBlockSize();

	GLfloat pointA_Y = pointB_Y + board.getBlockSize();
	GLfloat pointB_X = pointA_X + ((pointC_X - pointA_X) / 2);
	GLfloat pointC_Y = pointA_Y;
	
	glBegin(GL_TRIANGLES);
	glColor3f(frog.getColor().red, frog.getColor().green, frog.getColor().blue);
	glVertex2f(pointA_X, pointA_Y);
	glVertex2f(pointB_X, pointB_Y);
	glVertex2f(pointC_X, pointC_Y);
	glEnd();
};