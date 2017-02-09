#pragma once
#include "object.h"

class Frog : public Object
{
private:
	int lifes;
public:
	Frog(int x, int y, Color color, int lifes);
	~Frog();

	int getLifes() const;
	void removeLife();
};
