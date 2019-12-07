#include "Stage.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Game1vs1Scene.h"
#include "Path.h"
#include <memory>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


void Stage::memoryManage()
{
	if (gameScene != NULL) {
		delete gameScene;
		gameScene = NULL;
	}
	if (game1vs1Scene != NULL) {
		delete game1vs1Scene;
		game1vs1Scene = NULL;
	}
}

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

	Path path;
	menuScene = new MainMenuScene(this);
	menuScene->setBackground(path.BACKGROUND_MAIN_MENU);

}

Stage::~Stage()
{
	if(menuScene != NULL)
		delete menuScene;
	memoryManage();

	al_uninstall_system();
	std::cout << "Stage" << std::endl;
}


void Stage::showMenu()
{
	memoryManage();
	
	menuScene->showWindow();
}

void Stage::showGame()
{
	Path path;
	gameScene = new GameScene(this);
	gameScene->setBackground(path.BACKGROUND_GAME);
	gameScene->showWindow();
}

void Stage::showGame1vs1()
{
	Path path;
	game1vs1Scene = new Game1vs1Scene(this);
	game1vs1Scene->setBackground(path.BACKGROUND_GAME);
	game1vs1Scene->showWindow();

}

