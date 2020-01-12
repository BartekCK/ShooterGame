#include "GameScene.h"
#include "BuildEnemy.h"
#include "Music.h"

GameScene::GameScene(Stage* stage)
	: stage(stage)
{
	Path path;
	engine->startTimers();
	player = new Player(path.PLAYER, 10, 10, 16, 2, CONTROL_SOURCE::ARROW_CONTROL);
	heart = new Heart(path.OBJECT_HEART);

	if (engine->difficultyLevel == DifficultyLevel::EASY)
		this->HOW_MUTCH_KILL = 10;
	else if (engine->difficultyLevel == DifficultyLevel::MEDIUM)
		this->HOW_MUTCH_KILL = 20;
	else
		this->HOW_MUTCH_KILL = 25;
	
	enemies.push_back(BuildEnemy::getEnemy(player));
}

GameScene::~GameScene()
{
	engine->stopTimers();
	resetCamera();
	delete player;
	delete heart;

	for (size_t i = 0; i < enemies.size(); i++) {
		delete enemies[i];
	}
	
	enemies.clear();
	enemies.shrink_to_fit();

	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	Path path;
	Music* music = new Music(path.MUSIC_GAME, ChooseMusic::MUSIC);
	music->playMusic();
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
			if (events.timer.source == engine->timmerVector[3]) {
			
				randEnemy();
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

			heart->show();
			player->show();
			player->checkHit(enemies);//When players get hits by enemies

			for (size_t i = 0; i < enemies.size(); i++) {
				enemies[i]->show();
				enemies[i]->checkHit(player);//When enemies get hits by player
				
			}
		
			heart->checkHit(player);//To check that player touch the heart

			if (player->checkHp()) {//When player is dead
				done = true;
			}


			
			allocateMemory();//To delete death enemies
			al_flip_display();
		}

	}
	delete music;
	resetCamera();
	if (winGame) {
		this->stage->showWin();
	}else
		this->stage->showLose();
}


void GameScene::allocateMemory()
{
	vector<Hero *>::iterator it;
	for (it = enemies.begin(); it != enemies.end(); it++) {
		if ((*it)->checkHp()) {
			if (*it != NULL) {
				Hero* temp = *it;
				enemies.erase(it);
				delete temp;
				temp = NULL;
				countKilledEnemies++;
				break;
			}
		}
	}

	if (this->checkEnd) {
		if (enemyEnd != NULL) {
			if (enemyEnd->checkHp()) {
				enemyEnd = NULL;
				this->winGame = true;
				this->done = true;
			}
		}
		
	}

}

void GameScene::randEnemy()
{

	if (this->countKilledEnemies == HOW_MUTCH_KILL) {
		this->enemyEnd = BuildEnemy::getBoss(player);
		enemies.push_back(enemyEnd);
		this->checkEnd = true;
		countKilledEnemies = 99;
	}
	else if(this->countKilledEnemies <= HOW_MUTCH_KILL){
		srand(time(NULL));
		if (rand() % (int)Engine::difficultyLevel == 1) {


			Enemy* temp = BuildEnemy::getEnemy(player);

			do {
				if (temp) {
					enemies.push_back(temp);
					break;
				}
				else {
					Enemy* temp = BuildEnemy::getEnemy(player);

				}

			} while (temp == NULL);
		}
	}

}
