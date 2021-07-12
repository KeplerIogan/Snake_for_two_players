#include "Game.h"
#include "apple.h"
#include "Player_1.h"
#include "Snake.h"
#include "Snake_2.h"

int game(RenderWindow *window) {

	Snake_1 *Player_one = new Snake_1;
	Snake_2 *Player_two = new Snake_2;
	Apple *apple = new Apple;
	int lose = 0, i = 0;

	Player_one->spawn();
	Player_two->spawn();
	apple->spawn();


	
	Event event;

	while (true) {
		while (window->pollEvent(event)) {

			if (event.type == Event::Closed || event.key.code == Keyboard::Escape) {

				return 0;
			}
		}

		window->clear();
		apple->draw(window);
		Player_one->draw(window);
		Player_two->draw(window);
		window->display();


		if (i == 150) {

			Player_one->move(event, apple, window);
			lose = Player_one->punch(Player_two);

			if (lose == 1) {

				delete (Player_one);
				delete (Player_two);
				delete (apple);

				return 2;
			}

			Player_two->move(event, apple, window);
			lose = Player_two->punch(Player_one);

			if (lose == 2) {

				delete (Player_one);
				delete (Player_two);
				delete (apple);

				return 1;
			}

			i = 0;
		}
		i++;

	}
}


