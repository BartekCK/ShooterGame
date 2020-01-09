#pragma once
#include"Scene.h"
#include"Stage.h"
#include"Heart.h"
#include"Enemy.h" 

enum class DifficultyLevel {
	EASY = 8,
	MEDIUM = 6,
	HARD = 3,
};

class GameScene :public Scene
{
	Stage* stage = NULL;
	Player* player = NULL;
	Heart* heart = NULL;
	DifficultyLevel difficultyLevel = DifficultyLevel::HARD;
	int countKilledEnemies = 0;
	const int HOW_MUTCH_KILL = 5;
	std::vector<Hero*> enemies;


	void allocateMemory();
	void randEnemy();

public:
	GameScene(Stage* stage);
	~GameScene();
	void showWindow() override;



};
