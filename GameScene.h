#pragma once
#include"Scene.h"
#include"Stage.h"
#include"Heart.h"

class GameScene :public Scene
{
	Stage* stage = NULL;
	Player* player = NULL;
	Heart* heart = NULL;
	

public:
	GameScene(Stage* stage);
	~GameScene();
	void showWindow() override;



};
