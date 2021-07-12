#pragma once
#include "apple.h"

class Block
{
public:

	virtual void move(Apple*, int) = 0;
	virtual void growth(Apple*, int) = 0;
	virtual void delta_spawn(float, float) = 0;
	virtual void draw(RenderWindow*) = 0;

};

