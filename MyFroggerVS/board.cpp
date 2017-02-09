#include "board.h"

Board::Board(int blockSize, int rows, int cols, Position startPosition, int extremeLeft, int extremeRight,
	Position winPos1, Position winPos2, Position winPos3, Position winPos4, Position winPos5)
{
	this->blockSize = blockSize;	
	this->rows = rows;
	this->cols = cols;
	this->startPosition = startPosition;
	this->extremeLeft = extremeLeft;
	this->extremeRight = extremeRight;
	this->winPos1 = winPos1;
	this->winPos2 = winPos2;
	this->winPos3 = winPos3;
	this->winPos4 = winPos4;
	this->winPos5 = winPos5;
	this->achievedPos1 = false;
	this->achievedPos2 = false;
	this->achievedPos3 = false;
	this->achievedPos4 = false;
	this->achievedPos5 = false;
}

int Board::getBlockSize() const
{
	return blockSize;
}

int Board::getRows() const
{
	return rows;
}

int Board::getCols() const
{
	return cols;
}

Position Board::getStartPosition() const
{
	return startPosition;
}

int Board::getExtremeLeft() const
{
	return extremeLeft;
}

int Board::getExtremeRight() const
{
	return extremeRight;
}

bool Board::isWinPosition(int x, int y)
{
	if (x == winPos1.x && y == winPos1.y && !achievedPos1)
	{
		return true;
	}
	if (x == winPos2.x && y == winPos2.y && !achievedPos2)
	{
		return true;
	}
	if (x == winPos3.x && y == winPos3.y && !achievedPos3)
	{
		return true;
	}
	if (x == winPos4.x && y == winPos4.y && !achievedPos4)
	{
		return true;
	}
	if (x == winPos5.x && y == winPos5.y && !achievedPos5)
	{
		return true;
	}
	return false;
}

void Board::setAchievedPos(int x, int y)
{
	if (x == winPos1.x && y == winPos1.y)
	{
		achievedPos1 = true;
	}
	if (x == winPos2.x && y == winPos2.y)
	{
		achievedPos2 = true;
	}
	if (x == winPos3.x && y == winPos3.y)
	{
		achievedPos3 = true;
	}
	if (x == winPos4.x && y == winPos4.y)
	{
		achievedPos4 = true;
	}
	if (x == winPos5.x && y == winPos5.y)
	{
		achievedPos5 = true;
	}	
}