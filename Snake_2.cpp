#include "Snake_2.h"



Snake_2::Snake_2() : length(4)
{
	body->segment.setFillColor(sf::Color::Red);

	for (i = 1; i < 4; i++) {

		body->next = new Player_1(i, length);
		body = body->next;
		body->segment.setFillColor(sf::Color::Red);

	}

	body = Head->next;
}

void Snake_2::spawn()
{

	Head->delta_spawn(610, 230);
	body->delta_spawn(610, 250);
	body->next->delta_spawn(610, 270);
	body->next->next->delta_spawn(610, 290);
}

void Snake_2::move(Event event, Apple *app, RenderWindow *window)
{
	Player_1 check = *Head;
	Player_1 swap = *Head->next;
	int num = length;

	if (event.key.code == Keyboard::Up) {

		Head->delta_speed(0, -20);


	}
	else if (event.key.code == Keyboard::Down) {

		Head->delta_speed(0, 20);


	}
	else if (event.key.code == Keyboard::Left) {

		Head->delta_speed(-20, 0);


	}
	else if (event.key.code == Keyboard::Right) {

		Head->delta_speed(20, 0);

	}

	Head->move(app, length);
	Head->next->segment.setFillColor(sf::Color::Red);
	body = Head->next;

	while (true) {

		body->delta_spawn(check.getPosition_x(), check.getPosition_y());
		body->draw(window);
		check = swap;

		if (body->next != NULL) {

			swap = *body->next;
			body = body->next;

		}
		else {
			break;
		}
	}

	body = Head->next;
	Head->punch(Head, body, window);

}

void Snake_2::draw(RenderWindow *window)
{
	Head->draw(window);
	while (body != NULL) {
		body->draw(window);
		body = body->next;
	}
	body = Head->next;
}

int Snake_2::punch(Snake_1 *one)
{
	body = Head->next;
	one->body = one->Head->next;
	int num;

	if (Head->getPosition_x() == one->Head->getPosition_x() && Head->getPosition_y() == one->Head->getPosition_y()) {

		return 2;
	}

	while (one->body != NULL) {
		if (Head->getPosition_x() == one->body->getPosition_x() && Head->getPosition_y() == one->body->getPosition_y()) {

			return 2;
		}
		else {

			one->body = one->body->next;
		}
	}

	body = Head->next;
	one->body = one->Head->next;

	return 0;
}



