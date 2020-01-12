#pragma once
#include"Scene.h"
#include"Stage.h"
#include"Button.h"

class EndGame : public Scene
{
	Button* newGameButton = NULL;
	Stage* stage = NULL;
public:
	EndGame(Stage* stage);
	~EndGame();
	void showWindow() override;
};

