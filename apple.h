#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class Apple
{
private:

	float x, y;

	CircleShape apple;

public:

	Apple();

	void spawn();
	float getPosition_x();
	float getPosition_y();
	void draw(RenderWindow*);
};

