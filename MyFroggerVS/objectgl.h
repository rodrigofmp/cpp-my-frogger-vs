#pragma once

#include "object.h"
#include "board.h"

class ObjectGL
{
public:
	void static Draw(const Object& object, const Board& board);
};