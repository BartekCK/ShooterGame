#include "LevelScene.h"

LevelScene::LevelScene(Stage* stage) :stage(stage)
{
	Path path;
	this->easyButton = new Button(path.BUTTON_EASY);
	this->mediumButton = new Button(path.BUTTON_MEDIUM);
	this->hardButton = new Button(path.BUTTON_HARD);

	this->easyButton->setXposition((this->screen_width / 2) - (this->easyButton->getBitmapWidth() / 2));
	this->easyButton->setYposition((this->screen_height / 2) - (this->easyButton->getBitmapHeight() / 2) - 150);

	this->mediumButton->setXposition((this->screen_width / 2) - (this->mediumButton->getBitmapWidth() / 2));
	this->mediumButton->setYposition((this->screen_height / 2) - (this->mediumButton->getBitmapHeight() / 2) + 0);

	this->hardButton->setXposition((this->screen_width / 2) - (this->hardButton->getBitmapWidth() / 2));
	this->hardButton->setYposition((this->screen_height / 2) - (this->hardButton->getBitmapHeight() / 2) + 150);
}

LevelScene::~LevelScene()
{
	delete easyButton;
	delete mediumButton;
	delete hardButton;
	cout << "DESKTRUKTOR Z LEVEL_SCENE" << endl;
}

void LevelScene::showWindow()
{
	int x = 0, y = 0;
	this->done = false;
	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (events.mouse.button & 1) {
				x = events.mouse.x;
				y = events.mouse.y;
				if (this->easyButton->buttonClick(x, y)) {
					Engine::difficultyLevel = DifficultyLevel::EASY;
					break;
				}
				if (this->mediumButton->buttonClick(x, y)) {
					Engine::difficultyLevel = DifficultyLevel::MEDIUM;
					break;
				}
				if (this->hardButton->buttonClick(x, y)) {
					Engine::difficultyLevel = DifficultyLevel::HARD;
					break;
				}
			}

		}
		al_draw_bitmap(this->background, 0, 0, 0);

		this->easyButton->show();
		this->mediumButton->show();
		this->hardButton->show();
		al_flip_display();
	}

	this->stage->showGame();
}
