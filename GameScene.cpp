#include "GameScene.h"

GameScene::GameScene(Stage* stage)
	: stage(stage)
{
	Path path;

}

GameScene::~GameScene()
{

	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	bool move = false;
	this->done = false;

	engine->startTimers();

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {

			
			



			move = true;
		}

		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
			}
		}


		if (move == true) {
			move = false;
			al_draw_bitmap(this->background, 0, 0, 0);
			//Draw here





			al_flip_display();
		}

	}


	engine->stopTimers();
	this->stage->showMenu();

}


