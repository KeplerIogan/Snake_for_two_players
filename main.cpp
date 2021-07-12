#include "Game.h"
#include "Snake.h"
#include "Snake_2.h"
#include "time.h"


using namespace sf;

int main()
{
	srand(time(NULL));

	RenderWindow *window = new RenderWindow(VideoMode(800, 600), "SNAKE #2");

	Clock clock;
	Font font;
	font.loadFromFile("C:/WINDOWS/Fonts/arial.ttf");


	Text headline, headline_2, subtitle;
	headline.setFont(font);
	headline_2.setFont(font);
	subtitle.setFont(font);

	headline.setString("SNAKE #2");
	subtitle.setString("Press Enter for start");
	headline.setCharacterSize(65);
	headline_2.setCharacterSize(45);
	subtitle.setCharacterSize(25);
	headline.setPosition(100, 100);
	headline_2.setPosition(100, 170);
	subtitle.setPosition(100, 300);


	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();

	int i = 0, lose = 0, win = 0, absolyte_win = 0;

	while (window->isOpen())
	{		
		
		Event *event = new Event;


		while (window->pollEvent(*event))
		{
			if (event->type == Event::Closed || event->key.code == Keyboard::Escape) {

				window->close();
				return 0;
			}
		}

		window->clear();
		window->draw(headline);
		window->draw(headline_2);
		window->draw(subtitle);
		window->display();

		
		if (event->key.code == Keyboard::Enter) {

			headline_2.setString("");
			win = game(window);
			if (win == 1) {

				absolyte_win += 1;
				headline.setString("Player 1 win");
				if (absolyte_win == 1 || absolyte_win == 5) {
					subtitle.setString("Press Enter for begin 2 Round");
				}
				else if (absolyte_win == 6 ) {
					subtitle.setString("Press Enter for begin 3 Round");
				}
				
			}
			else if (win == 2) { 
			
				absolyte_win += 5;
				headline.setString("Player 2 win");
				if (absolyte_win == 1 || absolyte_win == 5) {
					subtitle.setString("Press Enter for begin 2 Round");
				}
				else if (absolyte_win == 6) {
					subtitle.setString("Press Enter for begin 3 Round");
				}
			
			}
		}
		if (absolyte_win == 2 || absolyte_win == 7) {
			headline.setString("Game Over!");
			headline_2.setString("Player 1 absolyte win!");
			subtitle.setString("Press Enter for restart and begin 1 Round");
			absolyte_win = 0;

		}
		else if (absolyte_win == 10 || absolyte_win == 11) {
			headline.setString("Game Over!");
			headline_2.setString("Player 2 absolyte win!");
			subtitle.setString("Press Enter for restart and begin 1 Round");
			absolyte_win = 0;
		}
	}

	return 0;
}