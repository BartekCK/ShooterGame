// ShooterGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include "Stage.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Game1vs1Scene.h"



int main()
{
	Path path;
	Stage* stage = new Stage();

	Scene* sceneMenu = new MainMenuScene(stage);
	Scene* sceneGame = new GameScene(stage);
	Scene* sceneGame1vs1 = new Game1vs1Scene(stage);

	sceneMenu->setBackground(path.BACKGROUND_MAIN_MENU);
	sceneGame->setBackground(path.BACKGROUND_GAME);
	sceneGame1vs1->setBackground(path.BACKGROUND_GAME);

	stage->setMenuScene(sceneMenu);
	stage->setGameScene(sceneGame);
	stage->setGame1vs1(sceneGame1vs1);

	stage->showMenu();



	Engine * engine = Engine::getInstance();
	delete engine;
	delete stage;
}

