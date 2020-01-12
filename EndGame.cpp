#include "EndGame.h"
#include "Path.h"


EndGame::EndGame(Stage* stage) : stage(stage)
{
	Path path;
	this->newGameButton = new Button(path.BUTTON_NEW_GAME);
	this->newGameButton->setXposition((this->screen_width / 2) - (this->newGameButton->getBitmapWidth() / 2));
	this->newGameButton->setYposition((this->screen_height) - (this->newGameButton->getBitmapHeight() / 2) - 150);
}

EndGame::~EndGame()
{
	delete this->newGameButton;
}

void EndGame::showWindow()
{
	int x = 0, y = 0;
	this->done = false;
	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (events.mouse.button & 1) {
				x = events.mouse.x;
				y = events.mouse.y;
				if (this->newGameButton->buttonClick(x, y)) {
					break;
				}
			}

		}
		al_draw_bitmap(this->background, 0, 0, 0);

		this->newGameButton->show();

		al_flip_display();
	}


	this->stage->showMenu();
}