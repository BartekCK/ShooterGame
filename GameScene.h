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
	int countKilledEnemies = 0;
	int HOW_MUTCH_KILL = 5;
	std::vector<Hero*> enemies;


	void allocateMemory();
	void randEnemy();

public:
	GameScene(Stage* stage);
	~GameScene();
	void showWindow() override;



};
