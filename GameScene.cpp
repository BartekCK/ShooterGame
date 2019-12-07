#include "GameScene.h"

GameScene::GameScene(Stage* stage)
	: stage(stage)
{
	Path path;
	engine->startTimers();
	player = new Player(path.PLAYER, 16, 2);
}

GameScene::~GameScene()
{
	engine->stopTimers();
	resetCamera();
	delete player;
	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	bool move = false;

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {

			
			
			cameraTransform(player);
			player->move(events, this->backgroundXPosition, this->backgroundWidth, this->backgroundHeight);


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
			drawBackground(player);
			player->show();
			

			al_flip_display();
		}

	}


	
	this->stage->showMenu();

}


