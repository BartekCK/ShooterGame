#include "Game1vs1Scene.h"
#include "Player.h"



Game1vs1Scene::Game1vs1Scene(Stage* stage)
	: stage(stage)
{
	Path path;
	engine->startTimers();
	
	players.push_back(new Player(path.PLAYER, 16, 2, CONTROL_SOURCE::ARROW_CONTROL));
	players.push_back(new Player(path.PLAYER, 16, 2, CONTROL_SOURCE::WASD_CONTROL));
}

Game1vs1Scene::~Game1vs1Scene()
{
	engine->stopTimers();
	delete players[0];
	delete players[1];
	players.clear();
	players.shrink_to_fit();
	cout << "DESTRUKTOR Z GAME_SCENE_1_VS_1" << endl;
}

void Game1vs1Scene::showWindow()
{
	bool move = false;


	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {


			players[0]->move(events,this->backgroundXPosition,this->backgroundWidth,this->backgroundHeight);
			players[1]->move(events,this->backgroundXPosition,this->backgroundWidth,this->backgroundHeight);
			internalBorders(players[0]);
			internalBorders(players[1]);
			
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


			players[0]->show();
			players[1]->show();
			al_flip_display();
		}

	}


	
	this->stage->showMenu();

}


void Game1vs1Scene::internalBorders(Player* player)
{
	if (player->getXposition() >= backgroundWidth - (player->getBitmapWidth() / 16)) {
		player->setXposition(backgroundWidth - (player->getBitmapWidth() / 16));
	}
}
