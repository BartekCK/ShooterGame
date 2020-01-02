#pragma once
#include"Scene.h"
#include"Stage.h"
#include"Heart.h"
#include"Enemy.h"

class GameScene :public Scene
{
	Stage* stage = NULL;
	Player* player = NULL;
	Heart* heart = NULL;

	std::vector<Hero*> enemies;


	

public:
	GameScene(Stage* stage);
	~GameScene();
	void showWindow() override;



};
