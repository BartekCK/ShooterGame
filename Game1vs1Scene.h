#pragma once

#include"Scene.h"
#include"Stage.h"

class Game1vs1Scene :public Scene
{
	Stage* stage = NULL;



public:
	Game1vs1Scene(Stage* stage);
	~Game1vs1Scene();
	void showWindow() override;



};
