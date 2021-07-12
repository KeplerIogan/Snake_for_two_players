#include "Snake.h"



Snake_1::Snake_1() : length(4)
{
	
	body->segment.setFillColor(sf::Color::Green);

	for (i = 1; i < 4; i++) {

		body->next = new Player_1(i, length);
		body = body->next;
		body->segment.setFillColor(sf::Color::Green);

	}

	body = Head->next;
	
}

void Snake_1::spawn()
{
	Head->delta_spawn(190, 230);
	body->delta_spawn(190, 250);
	body->next->delta_spawn(190, 270);
	body->next->next->delta_spawn(190, 290);
}

void Snake_1::move(Event event, Apple *app, RenderWindow *window)
{

	Player_1 check = *Head;
	Player_1 swap = *Head->next;
	int num = length;

	if (event.key.code == Keyboard::W) {

		Head->delta_speed(0, -20);

	
	} else if (event.key.code == Keyboard::S) {

		Head->delta_speed(0, 20);
		

	} else if(event.key.code == Keyboard::A) {

		Head->delta_speed(-20, 0);
	

	} else if(event.key.code == Keyboard::D) {

		Head->delta_speed(20, 0);
	
	}

	Head->move(app, length);
	Head->next->segment.setFillColor(sf::Color::Green);
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

void Snake_1::draw(RenderWindow *window)
{
	Head->draw(window);
	while (body != NULL) {
		body->draw(window);
		body = body->next;
	}
	body = Head->next;
}

int Snake_1::punch(Snake_2 *two)
{
	body = Head->next;
	two->body = two->Head->next;
	int num;

	if (Head->getPosition_x() == two->Head->getPosition_x() && Head->getPosition_y() == two->Head->getPosition_y()) {

		return 1;
	}
	
	while (two->body != NULL) {
		if (Head->getPosition_x() == two->body->getPosition_x() && Head->getPosition_y() == two->body->getPosition_y()) {

			return 1;
		} else {
		
			two->body = two->body->next;
		}
	}

	body = Head->next;
	two->body = two->Head->next;

	return 0;
}


