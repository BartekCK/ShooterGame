#pragma once
#include"Scene.h"
#include"Button.h"
#include"Stage.h"
#include"Path.h"
class HeroScene:public Scene
{
	Stage* stage = NULL;
	std::vector<Button*> buttonsFirst;
	std::vector<Button*> buttonsSecond;
	Button* newGameButton = NULL;
	string playerOne;
	string playerTwo;

public:
	HeroScene(Stage* stage);
	~HeroScene();
	virtual void showWindow() override;

private:
	void decodePath(string &player, int& frames);
	void calculateButtonPosition(int i, int& calcualteX, int& calcualteY, bool left);

};

