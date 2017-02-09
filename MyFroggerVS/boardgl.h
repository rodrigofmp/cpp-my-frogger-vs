#pragma once
#include "board.h"

class BoardGL
{
private:
	void static HomeSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom);
	void static RiverSideSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom);
	void static RiverSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom);
	void static FloorSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom);
	void static StreetSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom);
	void static GreenSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom);
	void static WhiteSquare(const GLfloat& posLeft, const GLfloat& posTop, const GLfloat& posRight, const GLfloat& posBottom);
public:
	void static Draw(const Board& board);
};
