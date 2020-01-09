#include "Stage.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Game1vs1Scene.h"
#include "LevelScene.h"
#include "HeroScene.h"
#include "Path.h"
#include <memory>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

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
	if (levelScene != NULL) {
		delete levelScene;
		levelScene = NULL;
	}
	if (heroScene != NULL) {
		delete heroScene;
		heroScene = NULL;
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
	al_init_primitives_addon();

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
	gameScene->setBackground(path.BACKGROUND_GAME_ADVENTURE);
	gameScene->showWindow();
}

void Stage::showGame1vs1()
{
	Path path;
	game1vs1Scene = new Game1vs1Scene(this);
	game1vs1Scene->setBackground(path.BACKGROUND_GAME);
	game1vs1Scene->showWindow();

}

void Stage::showLevel()
{
	Path path;
	levelScene = new LevelScene(this);
	levelScene->setBackground(path.BACKGROUND_MAIN_MENU);
	levelScene->showWindow();
}

void Stage::showHero()
{
	Path path;
	heroScene = new HeroScene(this);
	heroScene->setBackground(path.BACKGROUND_MAIN_MENU);
	heroScene->showWindow();
}

