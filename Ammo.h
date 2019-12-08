#pragma once
#include <allegro5/allegro.h>
#include "Engine.h"
#include "Node.h"

enum class SHOOT_DIRECTION
{
	RIGHT_SHOOT,
	LEFT_SHOOT
};

class Ammo:public Node
{
	Engine* engine = Engine::getInstance();
	int endXPosition = 0;
	int endYPosition = 0;
	int shotSpeed = 15;
	SHOOT_DIRECTION direction;
public:
	Ammo(int xPosition, int yPosition, SHOOT_DIRECTION direction);
	~Ammo();
	virtual void show() override;

	int getEndXPosition();
	int getEndYPosition();
	SHOOT_DIRECTION getDirection();
};

