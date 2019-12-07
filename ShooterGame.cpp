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

	stage->showMenu();

	Engine * engine = Engine::getInstance();


	delete engine;
	delete stage;
	
}

