#pragma once
#include "Scene.h"
#include "Button.h"
#include "Stage.h"

class MainMenuScene :public Scene
{
private:
	Button* newGameButton = NULL;
	Button* vsGameButton = NULL;
	Button* endGameButton = NULL;
	Stage* stage = NULL;

public:
	MainMenuScene(Stage* stage);
	virtual ~MainMenuScene();

	void showWindow() override;

};