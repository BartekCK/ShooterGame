#include "Stage.h"
#include "MainMenuScene.h"
#include "GameScene.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


Stage::Stage()
{
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro!\n");
		exit(0);
	}
	
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();
	al_install_audio();
	al_init_acodec_addon();
	al_init_font_addon();
	al_init_ttf_addon();
}

Stage::~Stage()
{

	delete menuScene;
	delete gameScene;
	delete game1vs1Scene;
	al_uninstall_system();
	std::cout << "Stage" << std::endl;
}

void Stage::setMenuScene(Scene* scene)
{
	this->menuScene = scene;
}

void Stage::setGameScene(Scene* scene)
{
	this->gameScene = scene;

}

void Stage::setGame1vs1(Scene* scene)
{
	this->game1vs1Scene = scene;
}

void Stage::showMenu()
{
	this->menuScene->showWindow();
}

void Stage::showGame()
{
	this->gameScene->showWindow();
}

void Stage::showGame1vs1()
{
	this->game1vs1Scene->showWindow();
}

