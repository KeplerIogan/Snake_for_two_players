#pragma once
#include "Apple.h"


class base_snake
{
public:
	
	virtual void spawn() = 0;
	virtual void move(Event, Apple*, RenderWindow*) = 0;
	virtual void draw(RenderWindow*) = 0;

};

