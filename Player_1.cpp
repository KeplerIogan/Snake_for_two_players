#include "Player_1.h"

using namespace sf;

Player_1::Player_1()
{

	segment.setSize(Vector2f(18, 18));
	segment.setOrigin({ 9, 9 });
	x = 0; y = 0;
	dx = 0; dy = -20;

}

Player_1::Player_1(int NUMBER, int length)
{
	
	number = NUMBER;

	if (number == 0) {
	
		segment.setSize(Vector2f(20, 20));
		segment.setOrigin({ 10, 10 });
		x = 0; y = 0;
		dx = 0; dy = -20;
	
	}
	else if (number == length - 1) {

		segment.setSize(Vector2f(16, 16));
		segment.setOrigin({ 8, 8 });
		next = NULL;
		x = 0; y = 0;
		dx = 0; dy = -20;

	}
	else {
	
		segment.setSize(Vector2f(18, 18));
		segment.setOrigin({ 9, 9 });
		x = 0; y = 0;
		dx = 0; dy = 0;

	}
}

void Player_1::delta_spawn(float X, float Y)
{
	x = X;
	y = Y;
	segment.setPosition(x, y);
}

void Player_1::delta_speed(float DX, float DY = -20)
{
	if (DX != -dx || DY != -dy) {
		dx = DX;
		dy = DY;
	}
}

void Player_1::move(Apple *app, int length)
{
	if (x + dx > 790) {

		x = -10;

	} else if (x + dx < 10) {
		
		x = 810;
	}
	if (y + dy > 590) {

		y = -10;

	} else if (y + dy < 10) {

		y = 610;
	}

	if (x + dx == app->getPosition_x() && y + dy == app->getPosition_y()) {
	
		growth(app, length);
	
	} else {

		x += dx;
		y += dy;

	}

	segment.setPosition(x, y);
}

void Player_1::punch(Player_1 *Head, Player_1 *body, RenderWindow *window)
{
	while (body != NULL) {
		if (Head->x == body->x && Head->y == body->y) {

			window->close();
		}
		else {
			
			body = body->next;
		}
	}
	body = Head->next;
}

void Player_1::growth(Apple *app, int length)
{
	Player_1 *new_segment = new Player_1;
	new_segment->next = next;
	next = new_segment;
	new_segment->x = x;
	new_segment->y = y;
	x += dx; y += dy;
	length++;
	segment.setPosition(x, y);
	new_segment->segment.setPosition(new_segment->x, new_segment->y);
	
	app->spawn();
	new_segment = next;

	while (new_segment != NULL) { //Контроль спавна яблока(чтоб на змейке не заспавнилось после поедания)
		
		if (((app->getPosition_x() == x) && (app->getPosition_y() == y)) || ((app->getPosition_x() == new_segment->x) && (new_segment->y == app->getPosition_y()))) {

			app->spawn();
			new_segment = next;
		
		} else {
			
			new_segment = new_segment->next;
		}

	}
}

void Player_1::draw(RenderWindow *window)
{
	window->draw(segment);
}

float Player_1::getPosition_x()
{
	return x;
}

float Player_1::getPosition_y()
{
	return y;
}



