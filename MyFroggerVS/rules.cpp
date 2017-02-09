#include "rules.h"

void Rules::WinPosition(Frog& frog, Board& board)
{
	if (board.isWinPosition(frog.getX(), frog.getY()))
	{
		board.setAchievedPos(frog.getX(), frog.getY());
	}
}