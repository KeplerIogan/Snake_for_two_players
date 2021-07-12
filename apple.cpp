#include "apple.h"



Apple::Apple()
{
	apple.setRadius(10);
	apple.setOrigin({10, 10});

}

void Apple::spawn()
{
	x = rand() % 39;
	x = x * 20 + 10;
	y = rand() % 29;
	y = y * 20 + 10;

	apple.setPosition(x, y);
}

float Apple::getPosition_x()
{
	return x;
}

float Apple::getPosition_y()
{
	return y;
}

void Apple::draw(RenderWindow *window)
{
	window->draw(apple);
}
