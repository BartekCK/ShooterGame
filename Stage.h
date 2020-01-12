#pragma once
#include <iostream> 

#include "Scene.h"
class Stage
{
	Scene* menuScene = NULL;
	Scene* winScene = NULL;
	Scene* loseScene = NULL;
	Scene* gameScene = NULL;
	Scene* levelScene = NULL;
	Scene* game1vs1Scene = NULL;
	Scene* heroScene = NULL;

	void memoryManage();

public:
	Stage();
	~Stage();

	void showMenu();
	void showGame();
	void showGame1vs1();
	void showLevel();
	void showHero();
	void showWin();
	void showLose();
	
};

