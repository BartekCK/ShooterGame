#include "GameScene.h"


GameScene::GameScene(Stage* stage)
	: stage(stage)
{
	Path path;
	engine->startTimers();
	player = new Player(path.PLAYER, 10, 10, 16, 2, CONTROL_SOURCE::ARROW_CONTROL);
	heart = new Heart(path.OBJECT_HEART);
	

	enemies.push_back(new Enemy(path.ENEMY_SMALL, 1000, 0, 10, 2, player));

}

GameScene::~GameScene()
{
	engine->stopTimers();
	resetCamera();
	delete player;
	delete heart;
	//delete enemy;//TEMP

	for (size_t i = 0; i < enemies.size(); i++) {
		delete enemies[i];
	}
	
	enemies.clear();
	enemies.shrink_to_fit();

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
			player->getHealthBar()->setXposition(this->cameraPosition);
			heart->calculateCoordinates(cameraPosition, screen_width, screen_height);



			for (size_t i = 0; i < enemies.size(); i++) {

				enemies[i]->move(events, this->backgroundXPosition, this->backgroundWidth, this->backgroundHeight);
				enemies[i]->makeShot(events);

			}

			
			


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


			player->checkHit(enemies);//TEST IT

			heart->show();
			player->show();



			for (size_t i = 0; i < enemies.size(); i++) {
				enemies[i]->show();
				enemies[i]->checkHit(player);

			}
		
			heart->checkHit(player);

			if (player->checkHp()) {
				done = true;
			}

			al_flip_display();
		}

	}


	
	this->stage->showMenu();

}


