#pragma once
#include"Scene.h"
#include"Button.h"
#include "Stage.h"

class LevelScene :public Scene
{
	Button* easyButton = NULL;
	Button* mediumButton = NULL;
	Button* hardButton = NULL;
	Stage* stage = NULL;

public:
	LevelScene(Stage* stage);
	virtual ~LevelScene();

	void showWindow() override;
};

