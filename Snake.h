#pragma once
#include "Player_1.h"
#include "Snake_2.h"
#include "Block.h"
#include "base_snake.h"

class Snake_1: public base_snake
{
	friend class Snake_2;

protected:

	Player_1 *body = new Player_1(0, 4);
	Player_1 *Head = body;

public:

	int length, i;

	Snake_1();

	void spawn() override;
	void move(Event, Apple*, RenderWindow*) override;
	void draw(RenderWindow*) override;
	int punch(Snake_2*);
};

