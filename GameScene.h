#pragma once
#include"Scene.h"
#include"Stage.h"

class GameScene :public Scene
{
	Stage* stage = NULL;

	

public:
	GameScene(Stage* stage);
	~GameScene();
	void showWindow() override;



};
