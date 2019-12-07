#include "Game1vs1Scene.h"
#include "Player.h"

Game1vs1Scene::Game1vs1Scene(Stage* stage)
	: stage(stage)
{
	Path path;

}

Game1vs1Scene::~Game1vs1Scene()
{

	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void Game1vs1Scene::showWindow()
{

	Path path;
	bool move = false;
	this->done = false;

	engine->startTimers();

	Player* player = new Player(path.PLAYER,16,2);


	

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {

			
			cameraTransform(player);

			player->move(events,this->backgroundXPosition,this->backgroundWidth,this->backgroundHeight);



			
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

	engine->stopTimers();
	delete player;

	resetCamera();
	this->stage->showMenu();

}


