#pragma once
#include "mobile.h"
#include "commons.h"

class Sinkable : public Mobile
{
private:
	SinkableStates state;
public: 
	Sinkable(int x, int y, Color color, int speed, int length);
	~Sinkable();

	void setState(SinkableStates const state);
};