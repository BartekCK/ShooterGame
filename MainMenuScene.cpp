#include "MainMenuScene.h"
#include "Music.h"


MainMenuScene::MainMenuScene(Stage* stage)
	:stage(stage)
{
	Path path;
	this->newGameButton = new Button(path.BUTTON_NEW_GAME);
	this->endGameButton = new Button(path.BUTTON_END_GAME);
	this->vsGameButton = new Button(path.BUTTON_1_VS_1);

	this->newGameButton->setXposition((this->screen_width / 2) - (this->newGameButton->getBitmapWidth() / 2));
	this->newGameButton->setYposition((this->screen_height / 2) - (this->newGameButton->getBitmapHeight() / 2) - 150);

	this->vsGameButton->setXposition((this->screen_width / 2) - (this->endGameButton->getBitmapWidth() / 2));
	this->vsGameButton->setYposition((this->screen_height / 2) - (this->endGameButton->getBitmapHeight() / 2) + 0);

	this->endGameButton->setXposition((this->screen_width / 2) - (this->endGameButton->getBitmapWidth() / 2));
	this->endGameButton->setYposition((this->screen_height / 2) - (this->endGameButton->getBitmapHeight() / 2) + 150);


}

MainMenuScene::~MainMenuScene()
{
	delete newGameButton;
	delete endGameButton;
	delete vsGameButton;
	cout << "DESKTRUKTOR Z MAIN_MENU_SCENE" << endl;
}

void MainMenuScene::showWindow()
{
	Path path;
	int x = 0, y = 0;
	bool newGame = false, newGame1vs1=false;
	this->done = false;
	Music* music = new Music(path.MUSIC_MENU, ChooseMusic::MUSIC);
	music->playMusic();
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
				if (this->vsGameButton->buttonClick(x, y)) {
					newGame1vs1 = true;
					break;
				}
				if (this->endGameButton->buttonClick(x, y)) {
					break;
				}
			}

		}
		al_draw_bitmap(this->background, 0, 0, 0);

		this->newGameButton->show();
		this->vsGameButton->show();
		this->endGameButton->show();
		al_flip_display();
	}
	delete music;
	if (newGame == true) {

		this->stage->showLevel();
	}
	if (newGame1vs1 == true) {

		this->stage->showHero();
	}
}