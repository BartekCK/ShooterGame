#pragma once

#include"Scene.h"
#include"Stage.h"
#include "Heart.h"

class Game1vs1Scene :public Scene
{
	Stage* stage = NULL;
	std::vector<Hero*> players;
	Heart* heart = NULL;
	void internalBorders(Hero* player);

public:
	Game1vs1Scene(Stage* stage);
	~Game1vs1Scene();
	void showWindow() override;



};
