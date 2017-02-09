#pragma once
#include "commons.h"

class Board
{
private:
	int blockSize, rows, cols, extremeLeft, extremeRight;
	Position startPosition, winPos1, winPos2, winPos3, winPos4, winPos5;
	bool achievedPos1, achievedPos2, achievedPos3, achievedPos4, achievedPos5;
public:
	Board(int blockSize, int rows, int cols, Position startPosition, int extremeLeft, int extremeRight, 
		Position winPos1, Position winPos2, Position winPos3, Position winPos4, Position winPos5);

	int getBlockSize() const;	
	int getRows() const;
	int getCols() const;
	Position getStartPosition() const;
	int getExtremeLeft() const;
	int getExtremeRight() const;

	bool isWinPosition(int x, int y);
	void setAchievedPos(int x, int y);
};
