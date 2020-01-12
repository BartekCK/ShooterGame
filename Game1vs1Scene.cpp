#include "Game1vs1Scene.h"
#include "Player.h"
#include "Music.h"


Game1vs1Scene::Game1vs1Scene(Stage* stage)
	: stage(stage)
{
	Path path;
	engine->startTimers();

	this->heart = new Heart(path.OBJECT_HEART);
	players.push_back(new Player(Engine::playerOne.c_str(), 10, screen_height / 2, Engine::framesOne, 2, CONTROL_SOURCE::WASD_CONTROL));
	players.push_back(new Player(Engine::playerTwo.c_str(), screen_width - 100, screen_height/2, Engine::framesTwo, 2, CONTROL_SOURCE::ARROW_CONTROL));

}

Game1vs1Scene::~Game1vs1Scene()
{
	engine->stopTimers();
	delete players[0];
	delete players[1];
	players.clear();
	players.shrink_to_fit();
	delete heart;
	cout << "DESTRUKTOR Z GAME_SCENE_1_VS_1" << endl;
}

void Game1vs1Scene::showWindow()
{
	bool move = false;
	Path path;
	Music* music = new Music(path.MUSIC_GAME, ChooseMusic::MUSIC);
	music->playMusic();

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {

			for (size_t i = 0; i < players.size(); i++) {
				players[i]->move(events, this->backgroundXPosition, this->backgroundWidth, this->backgroundHeight);
				internalBorders(players[i]);
			}
			heart->calculateCoordinates(cameraPosition, screen_width, screen_height);

			move = true;
		}
		

		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
			default:
				players[0]->makeShot(events);
				players[1]->makeShot(events);
			}

		}


		if (move == true) {
			move = false;
			al_draw_bitmap(this->background, 0, 0, 0);

			this->heart->show();

			for (size_t i = 0; i< players.size(); i++) {
				players[i]->checkHit(this->players);
				players[i]->show();

				if (players[i]->checkHp()) {
					done = true;
				}

				
				this->heart->checkHit(dynamic_cast<Player*>(players[i]));
			}

			
			
			
			

			al_flip_display();
		}

	}


	delete music;
	this->stage->showMenu();

}


void Game1vs1Scene::internalBorders(Hero* player)
{
	if (player->getXposition() >= backgroundWidth - (player->getBitmapWidth() / 16)) {
		player->setXposition(backgroundWidth - (player->getBitmapWidth() / 16));
	}
}
