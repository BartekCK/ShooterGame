#pragma once
#include"Hero.h"
#include"Engine.h"
#include "HealthBar.h"



enum class CONTROL_SOURCE
{
	ARROW_CONTROL,
	WASD_CONTROL
};


class Player :public Hero
{
	
	HealthBar* healthBar = NULL;

	CONTROL_SOURCE controlSource;
	void useBorders(float backgroundXPosition, int backgroundWidth, int backgroundHeight);
	void animation(ALLEGRO_EVENT events);
	void chooseShootDirection();
	
public:

	Player(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels, CONTROL_SOURCE controlSource);
	~Player();
	virtual void show() override;
	virtual void move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight) override;
	virtual void makeShot(ALLEGRO_EVENT events) override;
	void addHealth();
	HealthBar* getHealthBar();
	
	
};

