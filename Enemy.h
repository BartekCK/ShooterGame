#pragma once

#include"Hero.h"


class Enemy: public Hero
{
	Hero* player = NULL;




public:
	Enemy(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels, Hero * player);
	~Enemy();

	virtual void show() override;
	virtual void makeShot(ALLEGRO_EVENT events) override;
	virtual void move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight) override;
	void animation(ALLEGRO_EVENT events);//The same ? 

	
};

