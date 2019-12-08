#pragma once
#include <allegro5/allegro.h>
#include "Engine.h"
#include "Node.h"

enum class SHOOT_DIRECTION
{
	RIGHT_SHOOT,
	LEFT_SHOOT
};

class Ammo
{
	Engine* engine = Engine::getInstance();
	int endXPosition = 0;
	int endYPosition = 0;
	int shotSpeed = 15;
	SHOOT_DIRECTION direction;

	int xPosition = 0;
	int yPosition = 0;



public:
	Ammo(int xPosition, int yPosition, SHOOT_DIRECTION direction);
	~Ammo();
	void show();

	int getEndXPosition();
	int getEndYPosition();
	SHOOT_DIRECTION getDirection();


	void setXposition(int x);
	void setYposition(int y);
	int getXposition();
	int getYposition();


};

