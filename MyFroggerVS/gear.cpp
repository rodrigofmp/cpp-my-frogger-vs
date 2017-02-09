#include "gear.h"

void Gear::Move(Mobile& mobile, const Board& board)
{
	if (mobile.getX() > board.getExtremeLeft()) {
		mobile.setX(mobile.getX() - mobile.getSpeed());
	}
	else {
		mobile.setX(board.getExtremeRight());
	}
}