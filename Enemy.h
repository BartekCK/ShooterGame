#pragma once

#include"Hero.h"

enum class SHOOT_TIME
{
	SLOW = 3,
	MIDDLE = 4,
	FAST = 5,
};

enum class MOVE_SPEED {
	SLOW = 3,
	MIDDLE = 5,
	FAST = 9,
};

enum class HP_VALUE {
	LOW = 20,
	MIDDLE = 50,
	HARD = 70,
	SUPER_HARD = 200,
};


class Enemy: public Hero
{
	Hero* player = NULL;
	SHOOT_TIME shootTime;
	
public:
	
	Enemy(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels, HP_VALUE hpValue, MOVE_SPEED moveSpeed, SHOOT_TIME shootTime, Hero * player);
	virtual ~Enemy();

	virtual void show() override;
	virtual void makeShot(ALLEGRO_EVENT events) override;
	virtual void move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight) override;

	
};

