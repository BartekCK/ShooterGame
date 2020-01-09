#include "HeroScene.h"
#include <sstream>

HeroScene::HeroScene(Stage* stage) :stage(stage)
{
	Path path;
	playerOne = path.PLAYER;
	playerTwo = path.PLAYER;

	this->newGameButton = new Button(path.BUTTON_NEW_GAME);

	this->newGameButton->setXposition((this->screen_width / 2) - (this->newGameButton->getBitmapWidth() / 2));
	this->newGameButton->setYposition((this->screen_height) - (this->newGameButton->getBitmapHeight() / 2) - 150);

	buttonsFirst.push_back(new Button(path.MINIATURE_PLAYER));
	buttonsFirst.push_back(new Button(path.MINIATURE_ENEMY_BOSS));
	buttonsFirst.push_back(new Button(path.MINIATURE_ENEMY_SOLDIER));
	buttonsFirst.push_back(new Button(path.MINIATURE_ENEMY_SMALL_SOLDIER));
	buttonsFirst.push_back(new Button(path.MINIATURE_ENEMY_GALACTIC_SOLDIER));
	buttonsFirst.push_back(new Button(path.MINIATURE_ENEMY_ZOMBIE));
	buttonsFirst.push_back(new Button(path.MINIATURE_ENEMY_SMALL_ZOMBIE));

	buttonsSecond.push_back(new Button(path.MINIATURE_PLAYER));
	buttonsSecond.push_back(new Button(path.MINIATURE_ENEMY_BOSS));
	buttonsSecond.push_back(new Button(path.MINIATURE_ENEMY_SOLDIER));
	buttonsSecond.push_back(new Button(path.MINIATURE_ENEMY_SMALL_SOLDIER));
	buttonsSecond.push_back(new Button(path.MINIATURE_ENEMY_GALACTIC_SOLDIER));
	buttonsSecond.push_back(new Button(path.MINIATURE_ENEMY_ZOMBIE));
	buttonsSecond.push_back(new Button(path.MINIATURE_ENEMY_SMALL_ZOMBIE));

	int calcualteX = 0;
	int calcualteY = 0;

	for (size_t i = 0; i < buttonsFirst.size(); i++) {

		calculateButtonPosition(i, calcualteX, calcualteY, true);

		buttonsFirst[i]->setXposition(calcualteX);
		buttonsFirst[i]->setYposition(calcualteY);
	}
	
	for (size_t i = 0; i < buttonsSecond.size(); i++) {

		calculateButtonPosition(i, calcualteX, calcualteY, false);

		buttonsSecond[i]->setXposition(calcualteX);
		buttonsSecond[i]->setYposition(calcualteY);
	}
}

HeroScene::~HeroScene()
{
	for (size_t i = 0; i < buttonsFirst.size(); i++) {
		delete buttonsFirst[i];
		delete buttonsSecond[i];
	}
	buttonsFirst.clear();
	buttonsFirst.shrink_to_fit();
	buttonsSecond.clear();
	buttonsSecond.shrink_to_fit();

	delete newGameButton;
}

void HeroScene::showWindow()
{
	stringstream ss;
	int x = 0, y = 0;
	bool newGame = false;
	this->done = false;
	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (events.mouse.button & 1) {
				x = events.mouse.x;
				y = events.mouse.y;
				if (this->newGameButton->buttonClick(x, y)) {
					newGame = true;
					break;
				}


				for (size_t i = 0; i < buttonsFirst.size(); i++) {
					
					if (this->buttonsFirst[i]->buttonClick(x, y)) {
						ss.str("");
						ss<<buttonsFirst[i]->getPathBackgroundBitmap();
						playerOne = ss.str();
					}
					if (this->buttonsSecond[i]->buttonClick(x, y)) {
						ss.str("");
						ss << buttonsSecond[i]->getPathBackgroundBitmap();
						playerTwo = ss.str();
					}
			
				}
			}

		}
		al_draw_bitmap(this->background, 0, 0, 0);


		for (size_t i = 0; i < buttonsFirst.size(); i++) {
			buttonsFirst[i]->show();
			buttonsSecond[i]->show();
		}

		this->newGameButton->show();
		al_flip_display();
	}

	if (newGame == true) {

		Engine::playerOne = playerOne;
		Engine::playerTwo = playerTwo;

		decodePath(Engine::playerOne, Engine::framesOne);
		decodePath(Engine::playerTwo, Engine::framesTwo);

		this->stage->showGame1vs1();
	}
	
}

void HeroScene::decodePath(string &player, int &frames)
{
	Path path;
	const char* temp = player.c_str();

	if (strcmp(temp, path.MINIATURE_PLAYER) == 0) {
		player = path.PLAYER;
		frames = 16;
	}
	else if (strcmp(temp, path.MINIATURE_ENEMY_BOSS) == 0) {
		player = path.ENEMY_BOSS;
		frames = 11;
	}
	else if (strcmp(temp, path.MINIATURE_ENEMY_SOLDIER) == 0) {
		player = path.ENEMY_SOLDIER;
		frames = 10;
	}
	else if (strcmp(temp, path.MINIATURE_ENEMY_SMALL_SOLDIER) == 0) {
		player = path.ENEMY_SMALL_SOLDIER;
		frames = 6;
	}
	else if (strcmp(temp, path.MINIATURE_ENEMY_GALACTIC_SOLDIER) == 0) {
		player = path.ENEMY_GALACTIC_SOLDIER;
		frames = 17;
	}
	else if (strcmp(temp, path.MINIATURE_ENEMY_ZOMBIE) == 0) {
		player = path.ENEMY_ZOMBIE;
		frames = 19;
	}
	else if (strcmp(temp, path.MINIATURE_ENEMY_SMALL_ZOMBIE) == 0) {
		player = path.ENEMY_SMALL_ZOMBIE;
		frames = 8;
	}
}

void HeroScene::calculateButtonPosition(int i, int& calcualteX, int& calcualteY, bool left)
{
	if (left) {
		if (i < 3) {
			calcualteX += buttonsFirst[i]->getBitmapWidth();
			calcualteY = 0;
		}
		else if (i < 6) {
			calcualteX += buttonsFirst[i]->getBitmapWidth();
			calcualteY = buttonsFirst[i]->getBitmapWidth();

		}
		else {
			calcualteX = 0;
			calcualteY += buttonsFirst[i]->getBitmapWidth();

		}

		if (i == 3 || i == 0) {
			calcualteX = 0;
		}
	}
	else {
		if (i < 3) {
			calcualteX -= buttonsFirst[i]->getBitmapWidth();
			calcualteY = 0;
		}
		else if (i < 6) {
			calcualteX -= buttonsFirst[i]->getBitmapWidth();
			calcualteY = buttonsFirst[i]->getBitmapWidth();
		}
		else {
			calcualteY += buttonsFirst[i]->getBitmapWidth();
		}

		if (i == 3 || i == 0 || i == 6) {
			calcualteX = this->screen_width - buttonsSecond[i]->getBitmapWidth();
		}
	}
	
}
