#include "GameScene.h"


GameScene::GameScene(Stage* stage)
	: stage(stage)
{
	Path path;
	engine->startTimers();
	player = new Player(path.PLAYER, 10, 10, 16, 2, CONTROL_SOURCE::ARROW_CONTROL);
	heart = new Heart(path.OBJECT_HEART);
}

GameScene::~GameScene()
{
	engine->stopTimers();
	resetCamera();
	delete player;
	delete heart;
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
			heart->calculateCoordinates();





			move = true;
		}

		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
			default:
				player->makeShot(events);
			}
			
		}

		if (move == true) {
			move = false;
			drawBackground(player);


			heart->show();
			player->show();
		
			heart->checkHit(player);


			al_flip_display();
		}

	}


	
	this->stage->showMenu();

}


