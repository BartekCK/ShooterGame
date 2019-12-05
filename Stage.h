#pragma once
#include <iostream> 

#include "Scene.h"
class Stage
{
	Scene* menuScene = NULL;
	Scene* gameScene = NULL;
	Scene* game1vs1Scene = NULL;

public:
	Stage();
	~Stage();

	void setMenuScene(Scene* scene);
	void setGameScene(Scene* scene);
	void setGame1vs1(Scene* scene);

	void showMenu();
	void showGame();
	void showGame1vs1();
};

