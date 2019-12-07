#pragma once
#include <iostream> 

#include "Scene.h"
class Stage
{
	Scene* menuScene = NULL;
	Scene* gameScene = NULL;
	Scene* game1vs1Scene = NULL;

	void memoryManage();

public:
	Stage();
	~Stage();

	void showMenu();
	void showGame();
	void showGame1vs1();
};

