#pragma once
#include "Enemy.h"

class Zombie: public Enemy
{
public:
	Zombie(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels, HP_VALUE hpValue, MOVE_SPEED moveSpeed, SHOOT_TIME shootTime, Hero* player);
	~Zombie();
	virtual void makeShot(ALLEGRO_EVENT events) override;

};

