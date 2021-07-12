#pragma once
#include "Block.h"

class Player_1 : public Block
{
protected:

	float x, y, dx, dy;
	int number;

	

public:
	sf::RectangleShape segment;

	Player_1 *next;
	
	Player_1();
	Player_1(int, int);

	void delta_spawn(float, float) override;
	void delta_speed(float, float);
	void move(Apple*, int) override;
	void punch(Player_1*, Player_1*, RenderWindow*);
	void growth(Apple*, int) override;
	void draw(RenderWindow*) override;
	float getPosition_x();
	float getPosition_y();
};

