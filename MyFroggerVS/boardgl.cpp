#include <gl/freeglut.h>
#include "boardgl.h"
#include "commons.h"

void BoardGL::HomeSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f); // Verde		
	glVertex2f(posLeft, posTop);
	glVertex2f(posRight, posTop);
	glVertex2f(posRight, posBottom);
	glVertex2f(posLeft, posBottom);
	glEnd();
}

void BoardGL::RiverSideSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.2f, 0.0f); // Verde	
	glVertex2f(posLeft, posTop);
	glVertex2f(posRight, posTop);
	glVertex2f(posRight, posBottom);
	glVertex2f(posLeft, posBottom);
	glEnd();
}
void BoardGL::RiverSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom)
{
	glBegin(GL_QUADS);
	glColor3f(0.2f, 0.5f, 0.8f); // Azul	
	glVertex2f(posLeft, posTop);
	glVertex2f(posRight, posTop);
	glVertex2f(posRight, posBottom);
	glVertex2f(posLeft, posBottom);
	glEnd();
}
void BoardGL::FloorSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.7f); // Amarelo
	glVertex2f(posLeft, posTop);
	glVertex2f(posRight, posTop);
	glVertex2f(posRight, posBottom);
	glVertex2f(posLeft, posBottom);
	glEnd();
}
void BoardGL::StreetSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom)
{
	glBegin(GL_QUADS);
	glColor3f(0.7f, 0.7f, 0.7f); // Cinza
	glVertex2f(posLeft, posTop);
	glVertex2f(posRight, posTop);
	glVertex2f(posRight, posBottom);
	glVertex2f(posLeft, posBottom);
	glEnd();
}

void BoardGL::GreenSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f); // Verde			
	glVertex2f(posLeft, posTop);
	glVertex2f(posRight, posTop);
	glVertex2f(posRight, posBottom);
	glVertex2f(posLeft, posBottom);
	glEnd();
}

void BoardGL::WhiteSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(posLeft, posTop);
	glVertex2f(posRight, posTop);
	glVertex2f(posRight, posBottom);
	glVertex2f(posLeft, posBottom);
	glEnd();
}

void BoardGL::Draw(const Board& board)
{
	GLfloat posLeft = 0;
	GLfloat posRight = board.getBlockSize();
	//bool chess = true;

	for (int x = 1; x <= board.getCols(); x++)
	{
		GLfloat posBottom = 0;
		GLfloat posTop = board.getBlockSize();

		for (int y = 1; y <= board.getRows(); y++)
		{
			/*if (chess) {
				GreenSquare(posLeft, posTop, posRight, posBottom);
			}
			else {
				WhiteSquare(posLeft, posTop, posRight, posBottom);
			}
			chess = !chess;*/

			if (y == 1 && (x == 1 || x == 4 || x == 7 || x == 10 || x == 13) ) {
				HomeSquare(posLeft, posTop, posRight, posBottom);
			}

			if (y == 1 && (x == 2 || x == 3 || x == 5 || x == 6 || x == 8 || x == 9 || x == 11 || x == 12 )) {
				RiverSideSquare(posLeft, posTop, posRight, posBottom);
			}

			if (y > 1 && y < 6) {
				RiverSquare(posLeft, posTop, posRight, posBottom);
			}

			if (y == 6 || y == 11) {
				FloorSquare(posLeft, posTop, posRight, posBottom);
			}

			if (y > 6 && y < 11) {
				StreetSquare(posLeft, posTop, posRight, posBottom);
			}

			posBottom += board.getBlockSize();
			posTop += board.getBlockSize();
		}
		posLeft += board.getBlockSize();
		posRight += board.getBlockSize();
	}
}